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
    /* gimbal related */
    #define INIT_MIDDLE_YAW         5990 // these data are measured on infantry1.
    #define INIT_MIDDLE_PITCH       6000
    #define EVASIVE_LEFTMOST_YAW    7290
    #define EVASIVE_RIGHTMOST_YAW   4690
    #define PITCH_LOW_LIMIT         4800
    #define PITCH_HIGH_LIMIT        6200
    /* chassis related */
    #define MAX_TURN_SPEED          3000
    #define MAX_LINEAR_SPEED        8000
    #define MAX_SPEED               12000
    #define CHS_KP                  10
    #define CHS_KI                  0.9f
    #define CHS_KD                  0
    #define CHS_INT_LIM             200
    #define ROTATE_KP               2.7f

#elif defined(INFANTRY2)
    #define MEASURED_MIDDLE_YAW     5990
    #define MEASURED_MIDDLE_PITCH   6000

#elif defined(INFANTRY3)
    #define MEASURED_MIDDLE_YAW     5990
    #define MEASURED_MIDDLE_PITCH   6000

#elif defined(ENGINEERING)
    /* gimbal related */
    #define INIT_MIDDLE_YAW         400
    #define INIT_MIDDLE_PITCH       7000
    #define NORMAL_MIDDLE_YAW       400
    #define REVERSE_MIDDLE_YAW      4400
    #define EVASIVE_LEFTMOST_YAW    0    // no need for evasive mode
    #define EVASIVE_RIGHTMOST_YAW   0
    #define PITCH_LOW_LIMIT         5000
    #define PITCH_HIGH_LIMIT        7700
    /* chassis related */
    #define MAX_TURN_SPEED          4000
    #define MAX_LINEAR_SPEED        4500
    #define MAX_SPEED               9000
    #define CHS_KP                  10
    #define CHS_KI                  0.9f
    #define CHS_KD                  0
    #define CHS_INT_LIM             200
    #define ROTATE_KP               3.9f

#elif defined(HERO)
    #define MEASURED_MIDDLE_YAW     5990
    #define MEASURED_MIDDLE_PITCH   6000
#endif

#define IMU_DT          0.001f    // measurement time interval (in seconds). RTOS should give exact time to me.

#endif
