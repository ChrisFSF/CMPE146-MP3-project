#include "configargs.h"

#define GCCPLUGIN_VERSION_MAJOR   8
#define GCCPLUGIN_VERSION_MINOR   3
#define GCCPLUGIN_VERSION_PATCHLEVEL   1
#define GCCPLUGIN_VERSION  (GCCPLUGIN_VERSION_MAJOR*1000 + GCCPLUGIN_VERSION_MINOR)

static char basever[] = "8.3.1";
static char datestamp[] = "20190703";
static char devphase[] = "release";
static char revision[] = "[gcc-8-branch revision 273027]";

/* FIXME plugins: We should make the version information more precise.
   One way to do is to add a checksum. */

static struct plugin_gcc_version gcc_version = {basever, datestamp,
						devphase, revision,
						configuration_arguments};
