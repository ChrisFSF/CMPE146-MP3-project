#include "gpio_lab.h"
#include "FreeRTOS.h"
#include <stdio.h>

/// Should alter the hardware registers to set the pin as input
void gpiox__set_as_input(port_pin_s pin_num) {
  func_set_gpiox__iocon(pin_num, 0);
  if (!check_pin(pin_num)) {
    fprintf(stderr, "Set As Input: please re-enter the GPIO!\n");

  } else {
    // fprintf(stderr, "Succees to Set_As_Input P%u_%u\n", pin_num.port, pin_num.pin);
    switch (pin_num.port) {
    case 0:
      LPC_GPIO0->DIR &= ~(1 << pin_num.pin);
      break;
    case 1:
      LPC_GPIO1->DIR &= ~(1 << pin_num.pin);
      break;
    case 2:
      LPC_GPIO2->DIR &= ~(1 << pin_num.pin);
      break;
    }
  }
}

/// Should alter the hardware registers to set the pin as output
void gpiox__set_as_output(port_pin_s pin_num) {
  func_set_gpiox__iocon(pin_num, 0);
  if (!check_pin(pin_num)) {
    fprintf(stderr, "Set As Output: please re-enter the GPIO!\n");
  } else {
    // fprintf(stderr, "Succees to Set_As_Output P%u_%u\n", pin_num.port, pin_num.pin);
    switch (pin_num.port) {
    case 0:
      LPC_GPIO0->DIR |= (1 << pin_num.pin);
      break;
    case 1:
      LPC_GPIO1->DIR |= (1 << pin_num.pin);
      break;
    case 2:
      LPC_GPIO2->DIR |= (1 << pin_num.pin);
      break;
    }
  }
}

/// Should alter the hardware registers to set the pin as high
void gpiox__set_high(port_pin_s pin_num) {
  if (!check_pin(pin_num)) {
    fprintf(stderr, "Set High: please re-enter the GPIO!\n");
  } else {
    // fprintf(stderr, "Succees to Set_High P%u_%u\n", pin_num.port, pin_num.pin);
    switch (pin_num.port) {
    case 0:
      LPC_GPIO0->SET = (1 << pin_num.pin);
      break;
    case 1:
      LPC_GPIO1->SET = (1 << pin_num.pin);
      break;
    case 2:
      LPC_GPIO2->SET = (1 << pin_num.pin);
      break;
    }
  }
}

/// Should alter the hardware registers to set the pin as low
void gpiox__set_low(port_pin_s pin_num) {
  if (!check_pin(pin_num)) {
    fprintf(stderr, "Set Low: please re-enter the GPIO!\n");
  } else {
    // fprintf(stderr, "Succees to Set_Low P%u_%u\n", pin_num.port, pin_num.pin);
    switch (pin_num.port) {
    case 0:
      LPC_GPIO0->CLR = (1 << pin_num.pin);
      break;
    case 1:
      LPC_GPIO1->CLR = (1 << pin_num.pin);
      break;
    case 2:
      LPC_GPIO2->CLR = (1 << pin_num.pin);
      break;
    }
  }
}

/**
 * Should alter the hardware registers to set the pin as low
 *
 * @param {bool} high - true => set pin high, false => set pin low
 */
void gpiox__set(port_pin_s pin_num, bool high) {
  if (high == 1) {
    gpiox__set_high(pin_num);
  } else {
    gpiox__set_low(pin_num);
  }
}

/**
 * Should return the state of the pin (input or output, doesn't matter)
 *
 * @return {bool} level of pin high => true, low => false
 */
bool gpiox__get_level(port_pin_s pin_num) {
  if (!check_pin(pin_num)) {
    fprintf(stderr, "Get Level: please re-enter the GPIO!\n");
  } else {
    // fprintf(stderr, "Succees to Read_Level P%u_%u\n", pin_num.port, pin_num.pin);

    switch (pin_num.port) {
    case 0:
      return (LPC_GPIO0->PIN & (1 << pin_num.pin));
      break;
    case 1:
      return (LPC_GPIO1->PIN & (1 << pin_num.pin));
      break;
    case 2:
      return (LPC_GPIO2->PIN & (1 << pin_num.pin));
      break;
    }
  }
  return false;
}

bool check_pin(port_pin_s pin_num) {
  // fprintf(stderr, "Check Pin: P%u_%u\n", pin_num.port, pin_num.pin);
  if (pin_num.port == (uint8_t)5) {
    if (pin_num.pin > (uint8_t)4) {
      return false;
    }
  } else if (pin_num.port < (uint8_t)5) {
    if (pin_num.pin > (uint8_t)31) {
      return false;
    }
  } else if (pin_num.port > (uint8_t)5) {
    return false;
  }
  return true;
}

void func_set_gpiox__iocon(port_pin_s gpio, uint8_t func) {

  volatile uint32_t *IOCON_base = (volatile uint32_t *)LPC_IOCON; /// 0x4002 C000
  // fprintf(stderr, "LPC_IOCON: 0x%08x\n", IOCON_base);

  // Each port is offset by thirty-two 32-bit registers

  volatile uint32_t *port_offset = IOCON_base + (32 * gpio.port);
  // because gpio.port is int type, already a 4-byte value, 32*4 =128-->0x80
  // fprintf(stderr, "port_offset: 0x%08x\n", port_offset);

  // P0 0x4002 C000 (P0 + 0x80*0)
  // P1 0x4002 C080 (P0 + 0x80*1)
  // P2 0x4002 C100 (P0 + 0X80*2)
  // P3 0X4002 C180 (P0 + 0X80*3)
  // P4 0x4002 C200 (P0 + 0X80*4)
  // P5 0x4002 C280 (P0 + 0X80*5)

  // Each pin configuration is a single 32-bit

  volatile uint32_t *pin_iocon = (port_offset + gpio.pin);
  // fprintf(stderr, "set pin_iocon address from 0x%08x\n", pin_iocon);
  const uint32_t conf_mask = UINT32_C(7);
  *pin_iocon &= ~(conf_mask << 0);
  *pin_iocon |= ((uint32_t)func & conf_mask);
}

////////////////////////////Interrupt
void gpiox__setINT_Trigger_level(port_pin_s gpio, int Rising_or_Falling) {
  ////// 1 -->>> Rising, 0 -->>> Falling,////
  // fprintf(stderr, "set_int Check Pin: P%u_%u\n", gpio.port, gpio.pin);
  // Check Pin_input
  if (gpio.port != 0 && gpio.port != 2) {
    fprintf(stderr, "gpiox__setINT_Trigger_level: Wrong Port number input!\n");
  } else {

    switch (gpio.port) {
    case 0:                        /// select port
      switch (Rising_or_Falling) { // select Rising or Falling
      case 0:
        LPC_GPIOINT->IO0IntEnF |= (1 << gpio.pin);
        // fprintf(stderr, "setINT_Trigger_level: GPIOx_INTR_FALLING_EDGE P%u_%u\n", gpio.port, gpio.pin);

        break;

      case 1:
        LPC_GPIOINT->IO0IntEnR |= (1 << gpio.pin);
        // fprintf(stderr, "setINT_Trigger_level: GPIOx_INTR_RISING_EDGE P%u_%u\n", gpio.port, gpio.pin);

        break;
      }
      break;
    case 2:
      switch (Rising_or_Falling) { // select Rising or Falling
      case 0:
        LPC_GPIOINT->IO2IntEnF |= (1 << gpio.pin);
        // fprintf(stderr, "setINT_Trigger_level: GPIOx_INTR_FALLING_EDGE P%u_%u\n", gpio.port, gpio.pin);

        break;

      case 1:
        LPC_GPIOINT->IO2IntEnR |= (1 << gpio.pin);
        // fprintf(stderr, "setINT_Trigger_level: GPIOx_INTR_RISING_EDGE P%u_%u\n", gpio.port, gpio.pin);

        break;
      }
      break;
    }
  }
}

bool Check_signle_Int_Status(port_pin_s gpio, int Rising_or_Falling) {
  // Check Pin_input
  if (gpio.port != 0 && gpio.port != 2) {
    fprintf(stderr, "Check_signle_Int_Status: Wrong Port number input!\n");
  } else {
    switch (gpio.port) {
    case 0:                        /// select port 0
      switch (Rising_or_Falling) { // select Rising or Falling
      case 0:
        return (LPC_GPIOINT->IO0IntStatF & (1 << gpio.pin));
        break;

      case 1:
        return (LPC_GPIOINT->IO0IntStatR & (1 << gpio.pin));
        break;
      }
      break;
    case 2:                        // port 2
      switch (Rising_or_Falling) { // select Rising or Falling
      case 0:
        return (LPC_GPIOINT->IO2IntStatF & (1 << gpio.pin));
        break;

      case 1:
        return (LPC_GPIOINT->IO2IntStatR & (1 << gpio.pin));
        break;
      }
      break;
    }
  }
  return false;
}

bool Check_all_Int_Status() {
  // fprintf(stderr, "Check_all_Int_Status!\n");

  return (LPC_GPIOINT->IntStatus & 0xFFFFFFFF);
} // need to check whether it works

void Clear_Int(port_pin_s gpio) {
  if (gpio.port != 0 && gpio.port != 2) {
    fprintf(stderr, "Clear_Int: Wrong Port number input!\n");
  } else {
    switch (gpio.port) {
    case 0: /// select port 0
      LPC_GPIOINT->IO0IntClr |= (1 << gpio.pin);
      // fprintf(stderr, "Clear_Int: Success to CLR P%u_%u\n", gpio.port, gpio.pin);

      break;
    case 2: // port 2
      LPC_GPIOINT->IO2IntClr |= (1 << gpio.pin);
      // fprintf(stderr, "Clear_Int: Success to CLR P%u_%u\n", gpio.port, gpio.pin);

      break;
    }
  }
}
