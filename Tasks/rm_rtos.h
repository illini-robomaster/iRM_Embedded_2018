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
 * @author  Nickel_Liang
 * @date    2018-04-12
 * @file    rm_rtos.h
 * @brief   RTOS injection for the project
 * @log     2018-04-13 Nickel_Liang
 * @note    Functions and declarations for rtos should be written in this file.
 * @note    This file is included in ../Src/freertos.c to minimize the impact of future driver and middleware update.
 * @note    All functions should begin with "RM_" due to the nature of interaction with driver codes.
 */

#ifndef _RM_RTOS_H_
#define _RM_RTOS_H_

/* Includes */
#include "rm_config.h"
#include "bsp_print.h"
#include "bsp_buzzer.h"
#include "bsp_led.h"
#include "bsp_laser.h"
#include "bsp_sdio.h"
#include "bsp_key.h"
#include "task_referee.h"
#include "task_imu.h"
#include "task_motion.h"
#include "task_tx2.h"
#include "task_test.h"
#include "task_shoot.h"

/* RTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/**
 * Initialize after RTOS is initialized.
 *
 * @author  Nickel_Liang
 * @date    2018-04-13
 */
extern inline void RM_RTOS_Init(void) {
    /* Initialize RTOS */
    return;
}

/**
 * Initialize RTOS MUTEX
 *
 * @author  Nickel_Liang
 * @date    2018-04-13
 */
extern inline void RM_RTOS_MUTEX_Init(void) {
    return;
}

/**
 * Initialize RTOS SEMAPHORES
 *
 * @author  Nickel_Liang
 * @date    2018-04-13
 */
extern inline void RM_RTOS_SEMAPHORES_Init(void) {
    return;
}

/**
 * Initialize RTOS TIMERS
 *
 * @author  Nickel_Liang
 * @date    2018-04-13
 */
extern inline void RM_RTOS_TIMERS_Init(void) {
    return;
}

/**
 * Initialize RTOS THREADS
 *
 * @author  Nickel_Liang
 * @date    2018-04-13
 */
extern inline void RM_RTOS_THREADS_Init(void) {
    imu_task_create();
    tx2_task_create();
    referee_task_create();
#ifdef TEST
    test_task_create();
#else
    #if !defined(ENGINEERING) && !defined(HERO)
    shoot_task_create();
    #endif
    motion_task_create();
#endif
}

/**
 * Initialize RTOS QUEUES
 *
 * @author  Nickel_Liang
 * @date    2018-04-13
 */
extern inline void RM_RTOS_QUEUES_Init(void) {
    // sdio_queue_init();
    return;
}

/**
 * DefaultTask Jobs
 *
 * @param  argument   Same parameter passed in in Src/freertos.c
 * @author Nickel_Liang
 * @date   2018-04-13
 */
extern inline void RM_RTOS_Default_Task(void const * argument) {
    /* Add codes to initialize default thread here */
#ifdef DEBUG
    BSP_DEBUG;
    print("Enter default task.\n");
#endif
    //osTimerStart(gimbal_timer_id,gimbal_period);
    //osTimerStart(chassis_timer_id, chassis_period);
    // test_sdio();
    /* There must be a while loop here. */
    while(1) {
        osDelay(1);
    }
}

/**
 * RTOS is ready.
 *
 * @author Nickel_Liang
 * @date   2018-04-16
 */
extern inline void RM_RTOS_Ready() {
    /* Indicate RTOS booted. Ready to battle. */
    if (MUTE_MODE == OFF)
        buzzer_sing_song(startup);
    led_green_on();
    laser_on();
    print("RTOS initialzed. Ready to battle.\n");
}

#endif
