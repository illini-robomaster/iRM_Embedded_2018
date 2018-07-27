/**************************************************************************
 *  Copyright (C) 2018 
 *  Illini RoboMaster @ University of Illinois at Urbana-Champaign.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************/

/**
 * @author  Nickel_Liang <nickelliang>
 * @date    2018-05-22
 * @file    task_tx2.h
 * @brief   RTOS task for TX2(PC) tx and rx
 * @log     2018-05-22 nickelliang
 */

#ifndef _TASK_TX2_H_
#define _TASK_TX2_H_

#include "cmsis_os.h"
#include "tx2.h"

/* TX2 signal handling */
#define TX2_RX_SIGNAL   (1 << 2)
#define TX2_TX_SIGNAL   (1 << 3)

/* Global variable */
extern data_process_t   *tx2_process;
extern tx2_t            tx2_info;
extern osThreadId       tx2_task_handle;

/**
 * Create TX2 task
 *
 * @author Nickel_Liang
 * @date   2018-05-22
 */
void tx2_task_create(void);

/**
 * Initialize TX2 task software and hardware
 *
 * @return            1 for success, 0 for fail
 * @author Nickel_Liang
 * @date   2018-05-22
 */
uint8_t tx2_task_init(void);

/**
 * TX2 data processing task
 *
 * @param  argu       Passed in argument, usually un-used.
 * @author Nickel_Liang
 * @date   2018-05-22
 */
void tx2_task(void const *argu);

#endif
