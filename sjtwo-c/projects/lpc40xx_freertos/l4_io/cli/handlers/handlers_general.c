#include "cli_handlers.h"

#include "FreeRTOS.h"
#include "ff.h"
#include "task.h"
// #include <string.h>

#if (0 != configUSE_TRACE_FACILITY)
static void cli__task_list_print(sl_string_t user_input_minus_command_name, app_cli__print_string_function cli_output);
#endif

app_cli_status_e cli__crash_me(app_cli__argument_t argument, sl_string_t user_input_minus_command_name,
                               app_cli__print_string_function cli_output) {
  uint32_t *bad_pointer = (uint32_t *)0x00000001;
  *bad_pointer = 0xDEADBEEF;
  return APP_CLI_STATUS__SUCCESS;
}

static int file_index = 0;
static char file_name[10][16];

app_cli_status_e cli__scan_dir(app_cli__argument_t argument, sl_string_t user_input_minus_command_name,
                               app_cli__print_string_function cli_output) {
  char path[256];
  FRESULT res;
  DIR dir;
  UINT i;
  static FILINFO f_info;

  strncpy(path, user_input_minus_command_name, sizeof(path) - 1);
  res = f_opendir(&dir, path);
  if (res == FR_OK) {
    while (1) {
      res = f_readdir(&dir, &f_info);
      if (res != FR_OK || f_info.fname[0] == 0)
        break;
      if (f_info.fattrib & AM_DIR) {
        i = strlen(path);
        sprintf(&path[i], "/%s", f_info.fname);
        strncpy(file_name[file_index], f_info.fname, sizeof(path) - 1);
        file_index++;
        path[i] = 0;
      } else {
        printf("%s/%s\n", path, f_info.fname);
        strncpy(file_name[file_index], f_info.fname, sizeof(path) - 1);
        file_index++;
      }
    }
    f_closedir(&dir);
  }
  return APP_CLI_STATUS__SUCCESS;
}

app_cli_status_e cli__task_control(app_cli__argument_t arguement, sl_string_t user_input_minus_command_name,
                                   app_cli__print_string_function cli_output) {

  sl_string_t task = user_input_minus_command_name;
  app_cli_status_e command_status = APP_CLI_STATUS__HANDLER_FAILURE; // APP_CLI_STATUS__SUCCESS

  if (sl_string__begins_with_ignore_case(task, "suspend")) { // check keyword suspend
    sl_string__erase_first_word(task, ' ');
    TaskHandle_t task_handle = xTaskGetHandle(task);

    if (NULL == task_handle) {
      sl_string__insert_at(task, 0, "Suspend Could not find a task with name:");
      // cli_output(NULL, task);
    } else {
      vTaskSuspend(task_handle);
      command_status = APP_CLI_STATUS__SUCCESS;
    }
  } else if (sl_string__begins_with_ignore_case(task, "resume")) { // check keyword resume
    sl_string__erase_first_word(task, ' ');
    TaskHandle_t task_handle = xTaskGetHandle(task);

    if (NULL == task_handle) {
      sl_string__insert_at(task, 0, "Could not find a task with name:");
      // cli_output(NULL, task);
    } else {
      vTaskResume(task_handle);
      command_status = APP_CLI_STATUS__SUCCESS;
    }
  } else { // no match keyword
    cli_output(NULL, "Did you mean to say suspend or resume?\n");
    command_status = APP_CLI_STATUS__HANDLER_FAILURE;
  }

  return command_status;
}

#if (0 != configUSE_TRACE_FACILITY)
app_cli_status_e cli__task_list(app_cli__argument_t argument, sl_string_t user_input_minus_command_name,
                                app_cli__print_string_function cli_output) {
  const int sleep_time = sl_string__to_int(user_input_minus_command_name);
  if (sleep_time > 0) {
    vTaskResetRunTimeStats();
    vTaskDelay(sleep_time);
  }

  // re-use user_input_minus_command_name as 'output_string' to save memory:
  sl_string_t output_string = user_input_minus_command_name;
  cli__task_list_print(output_string, cli_output);

  return APP_CLI_STATUS__SUCCESS;
}

static void cli__task_list_print(sl_string_t output_string, app_cli__print_string_function cli_output) {
  // Enum to char : eRunning, eReady, eBlocked, eSuspended, eDeleted
  static const char *const task_status_table[] = {"running", " ready ", "blocked", "suspend", "deleted"};

  // Limit the tasks to avoid heap allocation.
  const unsigned portBASE_TYPE max_tasks = 10;
  TaskStatus_t status[max_tasks];
  uint32_t total_cpu_runtime = 0;
  uint32_t total_tasks_runtime = 0;

  void *unused_cli_param = NULL;
  const uint32_t total_run_time = portGET_RUN_TIME_COUNTER_VALUE();
  const unsigned portBASE_TYPE task_count = uxTaskGetSystemState(&status[0], max_tasks, &total_cpu_runtime);

  sl_string__printf(output_string, "%10s  Status Pr Stack CPU%%          Time\n", "Name");
  cli_output(unused_cli_param, output_string);

  for (unsigned priority_number = 0; priority_number < configMAX_PRIORITIES; priority_number++) {
    /* Print in sorted priority order */
    for (unsigned i = 0; i < task_count; i++) {
      const TaskStatus_t *task = &status[i];
      if (task->uxBasePriority == priority_number) {
        total_tasks_runtime += task->ulRunTimeCounter;

        const unsigned cpu_percent = (0 == total_cpu_runtime) ? 0 : task->ulRunTimeCounter / (total_cpu_runtime / 100);
        const unsigned time_us = task->ulRunTimeCounter;
        const unsigned stack_in_bytes = (sizeof(void *) * task->usStackHighWaterMark);

        sl_string__printf(output_string, "%10s %s %2u %5u %4u %10u us\n", task->pcTaskName,
                          task_status_table[task->eCurrentState], (unsigned)task->uxBasePriority, stack_in_bytes,
                          cpu_percent, time_us);
        cli_output(unused_cli_param, output_string);
      }
    }
  }

  sl_string__printf(output_string, "Overhead: %u uS\n", (unsigned)(total_run_time - total_tasks_runtime));
  cli_output(unused_cli_param, output_string);
}
#else
app_cli_status_e cli__task_list(app_cli__argument_t argument, sl_string_t user_input_minus_command_name,
                                app_cli__print_string_function cli_output) {
  cli_output(argument, "ERROR: configUSE_TRACE_FACILITY needs to be enabled at FreeRTOSConfig.h\n");
  return APP_CLI_STATUS__SUCCESS;
}
#endif /* configUSE_TRACE_FACILITY */
