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

#ifndef LIB_CONFIG_H_
#define LIB_CONFIG_H_

#include "main.h"

#if defined(INFANTRY1)
   /* shooter related */
    #define HAS_SHOOTER
    #define USE_PWM_FLYWHL
    #define FLYWHL_PWM_TIMER        &htim1
    #define FLYWHL_LEFT_CHANNEL     4
    #define FLYWHL_RIGHT_CHANNEL    1
    #define FLYWHL_TYPE             M2305
    #define POKER_ID                0x208
    #define POKER_CAN               CAN1_ID
    #define POKER_TYPE              M2006
    #define FLYWHL_OUTPUT           200
    /* gimbal related */
    #define INIT_MIDDLE_YAW         3150 // these data are measured on infantry2.
    #define EVASIVE_LEFTMOST_YAW    4150
    #define EVASIVE_RIGHTMOST_YAW   2150
    #define INIT_MIDDLE_PITCH       3800
    #define PITCH_LOW_LIMIT         3300
    #define PITCH_HIGH_LIMIT        4600
    /* chassis related */
    #define MAX_TURN_SPEED          3000
    #define EVASIVE_TURN_SPEED      2000
    #define MAX_LINEAR_SPEED        7000
    #define MAX_SPEED               12000
    #define CHS_KP                  6.5f
    #define CHS_KI                  0.7f
    #define CHS_KD                  1.3f
    #define CHS_INT_LIM             5000
    #define ROTATE_KP               3.5f

#elif defined(INFANTRY2)
    /* shooter related */
    #define HAS_SHOOTER
    #define USE_PWM_FLYWHL
    #define FLYWHL_PWM_TIMER        &htim1
    #define FLYWHL_LEFT_CHANNEL     4
    #define FLYWHL_RIGHT_CHANNEL    1
    #define FLYWHL_TYPE             M2305
    #define POKER_ID                0x208
    #define POKER_CAN               CAN1_ID
    #define POKER_TYPE              M2006
    #define FLYWHL_OUTPUT           200
    /* gimbal related */
    #define INIT_MIDDLE_YAW         6400 // these data are measured on infantry1.
    #define INIT_MIDDLE_PITCH       6500
    #define EVASIVE_LEFTMOST_YAW    7400
    #define EVASIVE_RIGHTMOST_YAW   5400
    #define PITCH_LOW_LIMIT         6000
    #define PITCH_HIGH_LIMIT        7300
    /* chassis related */
    #define MAX_TURN_SPEED          3000
    #define EVASIVE_TURN_SPEED      2000
    #define MAX_LINEAR_SPEED        7000
    #define MAX_SPEED               12000
    #define CHS_KP                  6.5f
    #define CHS_KI                  0.7f
    #define CHS_KD                  1.3f
    #define CHS_INT_LIM             5000
    #define ROTATE_KP               3.5f

#elif defined(INFANTRY3)
    /* shooter related */
    #define HAS_SHOOTER
    #define USE_PWM_FLYWHL
    #define FLYWHL_PWM_TIMER        &htim1
    #define FLYWHL_LEFT_CHANNEL     4
    #define FLYWHL_RIGHT_CHANNEL    1
    #define FLYWHL_TYPE             M2305
    #define POKER_ID                0x208
    #define POKER_CAN               CAN1_ID
    #define POKER_TYPE              M2006
    #define FLYWHL_OUTPUT           200
    /* gimbal related */
    #define INIT_MIDDLE_YAW         6260 // these data are measured on infantry2.
    #define EVASIVE_LEFTMOST_YAW    7500
    #define EVASIVE_RIGHTMOST_YAW   5000
    #define INIT_MIDDLE_PITCH       4500
    #define PITCH_LOW_LIMIT         4000
    #define PITCH_HIGH_LIMIT        5300
    /* chassis related */
    #define MAX_TURN_SPEED          3000
    #define EVASIVE_TURN_SPEED      2000
    #define MAX_LINEAR_SPEED        7000
    #define MAX_SPEED               12000
    #define CHS_KP                  6.5f
    #define CHS_KI                  0.7f
    #define CHS_KD                  1.3f
    #define CHS_INT_LIM             5000
    #define ROTATE_KP               3.5f

#elif defined(ENGINEERING)
    /* High Voltage Control MOSFET define */
    #define MAGNET_Pin MOS_CTL3_Pin
    #define MAGNET_GPIO_Port MOS_CTL3_GPIO_Port
    /* gimbal related */
    #define INIT_MIDDLE_YAW         400
    #define INIT_MIDDLE_PITCH       5000
    #define NORMAL_MIDDLE_YAW       400
    #define REVERSE_MIDDLE_YAW      4400
    #define HORIZONTAL_MIDDLE_YAW   6520
    #define EVASIVE_LEFTMOST_YAW    7520
    #define EVASIVE_RIGHTMOST_YAW   5520
    #define PITCH_LOW_LIMIT         5000
    #define PITCH_HIGH_LIMIT        7700
    /* chassis related */
    #define MAX_TURN_SPEED          4500
    #define EVASIVE_TURN_SPEED      1800
    #define MAX_LINEAR_SPEED        9500
    #define MAX_SPEED               14000
    #define CHS_KP                  7
    #define CHS_KI                  0.9f
    #define CHS_KD                  1.0f
    #define CHS_INT_LIM             5000
    #define ROTATE_KP               7.8f

#elif defined(HERO)
    /* shooter related */
    #define HAS_SHOOTER
    #define USE_CAN_FLYWHL
    #define FLYWHL_TYPE             M3508
    #define POKER_ID                0x208
    #define POKER_CAN               CAN1_ID
    #define POKER_TYPE              M2006
    #define FLYWHL_OUTPUT           220
    /* High Voltage Control MOSFET define */
    #define PNEUMATIC_GRAB_EXTEND_Pin       MOS_CTL1_Pin
    #define PNEUMATIC_GRAB_EXTEND_Port      MOS_CTL1_GPIO_Port
    #define GRABBER_Pin                     MOS_CTL2_Pin
    #define GRABBER_Port                    MOS_CTL2_GPIO_Port
    #define FRONT_LIFT_Pin                  MOS_CTL3_Pin
    #define FRONT_LIFT_Port                 MOS_CTL3_GPIO_Port
    #define REAR_LIFT_Pin                   MOS_CTL4_Pin
    #define REAR_LIFT_Port                  MOS_CTL4_GPIO_Port
    /* gimbal related */
    #define INIT_MIDDLE_YAW         4650 // these data are measured on infantry2.
    #define EVASIVE_LEFTMOST_YAW    5550
    #define EVASIVE_RIGHTMOST_YAW   3750
    #define INIT_MIDDLE_PITCH       2400
    #define PITCH_LOW_LIMIT         1600
    #define PITCH_HIGH_LIMIT        3100
    /* chassis related */
    #define MAX_TURN_SPEED          2000
    #define EVASIVE_TURN_SPEED      1500
    #define MAX_LINEAR_SPEED        2500
    #define MAX_SPEED               12000
    #define CHS_KP                  6.2f
    #define CHS_KI                  0.6f
    #define CHS_KD                  1.2f
    #define CHS_INT_LIM             5000
    #define ROTATE_KP               2.5f
#endif

#define IMU_DT          0.001f    // measurement time interval (in seconds). RTOS should give exact time to me.

#endif
