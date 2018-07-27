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

#ifndef _IMU_TASK_H_
#define _IMU_TASK_H_

#include "cmsis_os.h"

/* Global variable */
extern osThreadId   imu_task_handle;

/**
 * Create IMU task. Called in RTOS
 * @brief
 */
void imu_task_create(void);

/**
 * Irrelevant to RTOS. Just served as helper function to initialize IMU(s).
 * @brief
 * @return  1 means success. 0 means failure.
 */
uint8_t imu_task_init(void);

/**
 * RTOS thread. Periodically update IMU angles
 * @brief
 * @param argu RTOS arguments
 */
void imu_task(void const *argu);

#endif
