/*
 * Copyright (c) 2016 Chris Johns <chrisj@rtems.org>.  All rights reserved.
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#if !defined(_DL_LOAD_H_)
#define _DL_LOAD_H_

#ifdef __cplusplus
extern "C" {
#endif

void exception_base(bool istrue);
void exception_dl(void);

int dl_load_test(void);

#ifdef __cplusplus
}
#endif

#endif