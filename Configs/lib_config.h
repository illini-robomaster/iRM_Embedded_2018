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
    #define FLYWHL_OUTPUT           250
    /* gimbal related */
    #define INIT_MIDDLE_YAW         6400 // these data are measured on infantry1.
    #define INIT_MIDDLE_PITCH       6500
    #define EVASIVE_LEFTMOST_YAW    7400
    #define EVASIVE_RIGHTMOST_YAW   5400
    #define PITCH_LOW_LIMIT         6000
    #define PITCH_HIGH_LIMIT        7300
    /* chassis related */
    #define MAX_TURN_SPEED          3000
    #define EVASIVE_TURN_SPEED      3000
    #define MAX_LINEAR_SPEED        8000
    #define MAX_SPEED               12000
    #define CHS_KP                  6.5f
    #define CHS_KI                  0.5f
    #define CHS_KD                  1.0f
    #define CHS_INT_LIM             100000
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
    #define FLYWHL_OUTPUT           250
    /* gimbal related */
    #define INIT_MIDDLE_YAW         2300 // these data are measured on infantry2.
    #define INIT_MIDDLE_PITCH       6500
    #define EVASIVE_LEFTMOST_YAW    7500
    #define EVASIVE_RIGHTMOST_YAW   5500
    #define PITCH_LOW_LIMIT         6000
    #define PITCH_HIGH_LIMIT        7300
    /* chassis related */
    #define MAX_TURN_SPEED          3000
    #define EVASIVE_TURN_SPEED      3000
    #define MAX_LINEAR_SPEED        8000
    #define MAX_SPEED               12000
    #define CHS_KP                  6.5f
    #define CHS_KI                  0.5f
    #define CHS_KD                  1.0f
    #define CHS_INT_LIM             100000
    #define ROTATE_KP               3.5f

#elif defined(INFANTRY3)
    #define MEASURED_MIDDLE_YAW     5990
    #define MEASURED_MIDDLE_PITCH   6000

#elif defined(ENGINEERING)
    /* gimbal related */
    #define INIT_MIDDLE_YAW         400
    #define INIT_MIDDLE_PITCH       7000
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
    #define CHS_KP                  8
    #define CHS_KI                  0.9f
    #define CHS_KD                  1.0f
    #define CHS_INT_LIM             100000
    #define ROTATE_KP               7.5f

#elif defined(HERO)
    #define MEASURED_MIDDLE_YAW     5990
    #define MEASURED_MIDDLE_PITCH   6000
#endif

#define IMU_DT          0.001f    // measurement time interval (in seconds). RTOS should give exact time to me.

#endif
