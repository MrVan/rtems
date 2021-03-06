/*
 *  TOP Command Implementation
 *
 *  COPYRIGHT (c) 2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>

#include <rtems.h>
#include <rtems/cpuuse.h>
#include <rtems/printer.h>
#include <rtems/shell.h>
#include "internal.h"

static int rtems_shell_main_top(
  int   argc,
  char *argv[]
)
{
  /*
   *  When invoked with no arguments, print the report.
   */
  if ( argc == 1 ) {
    rtems_printer printer;
    rtems_print_printer_fprintf(&printer, stdout);
    rtems_cpu_usage_top_with_plugin(&printer);
    return 0;
  }

  /*
   *  When invoked with the single argument -r, reset the statistics.
   */
  if ( argc == 2 && !strcmp( argv[1], "-r" ) ) {
    printf( "Resetting CPU Usage information\n" );
    rtems_cpu_usage_reset();
    return 0;
  }

  /*
   *  OK.  The user did something wrong.
   */
  fprintf( stderr, "%s: [-r]\n", argv[0] );
  return -1;
}

rtems_shell_cmd_t rtems_shell_TOP_Command = {
  "top",                                      /* name */
  "[-r] print or reset per thread cpu usage", /* usage */
  "rtems",                                    /* topic */
  rtems_shell_main_top,                       /* command */
  NULL,                                       /* alias */
  NULL                                        /* next */
};
