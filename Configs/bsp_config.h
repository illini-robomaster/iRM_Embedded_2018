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
 * @date    2018-04-16
 * @file    bsp_config.h
 * @brief   Configure BSP ports
 * @log     2018-04-16 nickelliang
 */

#ifndef _BSP_CONFIG_H_
#define _BSP_CONFIG_H_

#include "stm32f4xx_hal.h"
#include "usart.h"

/**
 * @ingroup bsp
 * @defgroup bsp_config BSP CONFIG
 * @{
 */

/* ===== bsp_uart config ===== */
#define UART_FREE_PORT      huart3  // This port require solder pins onto the board

#define BSP_DBUS_PORT       huart1
#define BSP_PRINT_PORT      huart7
#define BSP_TX2_PORT        UART_FREE_PORT
#define BSP_REFEREE_PORT    huart6

#define BSP_DBUS_MAX_LEN    50      // Adjust according to actual message length. Should be longer than expected message length.
#define BSP_REFEREE_MAX_LEN 1024
#define BSP_TX2_MAX_LEN     64

#define UART_TX_BLOCKING_TIMEOUT    100

/* ===== bsp_print config ===== */
#define PRINT_TO_UART       1   // Set to 1 to print to uart port specified above
#define PRINT_TO_SD         0   // Not supported yet

/* ===== bsp_adc config ===== */
#define BSP_ADC_MAX_SAMPLE_SIZE 500
#define BSP_ADC_MAX_VOLT        3.3
#define BSP_ADC_MAX_ADC_OUT     4095

/* ==== bsp_power config ==== */
#define BSP_POWER_ADC               hadc1
#define BSP_POWER_V_CHANNEL         0
#define BSP_POWER_A_CHANNEL         1
#define BSP_POWER_AVG_FILTER_SIZE   50

/* ==== bsp_buzzer config ==== */
#define BSP_BUZZER_TIMER    htim12
#define BSP_BUZZER_CHANNEL  TIM_CHANNEL_1

/* ==== bsp_oled config ==== */
#define BSP_OLED_ADC                hadc1
#define BSP_OLED_ADC_CHANNEL        0

/* ===== General Utility ===== */
#define ON      1
#define OFF     0
#define DISABLE 2 // Not avaliable due to a conflict

/** @} */

#endif
