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

#ifndef _MOTION_TASK_H_
#define _MOTION_TASK_H_

#include "cmsis_os.h"

/* Start User Include */
#include "dbus.h"
#include "motor.h"
#include "chassis.h"
#include "gimbal.h"
#include "imu_onboard.h"
#include "referee.h"
#include "bsp_power.h"
/* End User Include */

#define MOTION_CYCLE 20

/* Global variable */
extern osThreadId chassis_task_handle;
extern osThreadId gimbal_task_handle;

extern gimbal_t my_gimbal;
extern pid_ctl_t* my_chassis[4];

typedef enum {
    NORMAL,
    HORIZONTAL,
    REVERSE,
}   motion_mode_t;

int power_ctl_curve(float cur_power);

/**
 * get current yaw angle for gimbal
 * @brief
 * @param gimbal_motor ptr for gimbal motor. We need feedback from it.
 * @return  current yaw angle for gimbal in degree (without wrap around. E.g., you may get 370)
 */
float get_gimbal_yaw_angle(motor_t *gimbal_motor);

/**
 * RTOS helper function to create thread for motion task
 * @brief
 */
void motion_task_create(void);

/**
 * RTOS thread function. SHOULD NEVER RETURN.
 * @brief
 * @param argu RTOS arguments
 */
void chassis_task(void const *argu);

/**
 * RTOS thread function. SHOULD NEVER RETURN.
 * @brief
 * @param argu RTOS arguments
 */
void gimbal_task(void const *argu);

#endif
