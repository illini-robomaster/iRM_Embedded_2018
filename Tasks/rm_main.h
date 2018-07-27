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
 * @file    rm_main.h
 * @brief   RM MAIN Insertion file.
 * @log     2018-04-13 Nickel_Liang
 * @note    Functions and declarations for main should be written in this file.
 * @note    This file is included in ../Src/main.c to minimize the impact of future driver and middleware update.
 * @note    All functions should begin with "RM_" due to the nature of interaction with driver codes.
 */

/** @defgroup library User Library */
/** @defgroup bsp BSP Library */

#ifndef _RM_MAIN_H_
#define _RM_MAIN_H_

/* Includes */
#include "rm_config.h"
#include "bsp_print.h"
#include "bsp_buzzer.h"
#include "bsp_can.h"
#include "bsp_gpio.h"
#include "bsp_led.h"
#include "bsp_uart.h"
#include "bsp_imu.h"
#include "bsp_sdio.h"
#include "dbus.h"

/**
 * Initialize peripherals before get into RTOS
 *
 * @author  Nickel Liang
 * @date    2018-04-13
 */
extern inline void RM_Main_Init(void) {
    led_red_on();
    buzzer_init();
    if (MUTE_MODE == OFF)
        buzzer_sing_song(initialize); // Control board power up.
    can1_init();
    can2_init();
    dbus_init();
    onboard_imu_init();
    // sdio_init(); // SD IO not quite working yet
    // key_init(); // key debouncing not quite working under RTOS

    /* Indicate successfully initialized */
    led_yellow_on();
    print("All peripherals initialized.\r\n");

    /* Wait for ESC to initialize */
    /* @todo change to more delicate CAN bus condition check function */
    HAL_Delay(STARTUP_DELAY);
    return;
}

#endif
