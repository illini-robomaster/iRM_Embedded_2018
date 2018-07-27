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

#include "task_imu.h"
#include "imu_onboard.h"

static osEvent imu_event;
osThreadId imu_task_handle;

void imu_task_create(void){
    /* initialize imu, do not move robot */
    imu_task_init();
    /* create thread and enter non-blocking logic */
    osThreadDef(imuTask, imu_task, osPriorityNormal, 0, 256);
    imu_task_handle = osThreadCreate(osThread(imuTask), NULL);
#ifdef DEBUG
    BSP_DEBUG;
    if (imu_task_handle == NULL)
        print("IMU task create failed.\r\n");
    else
        print("IMU task created.\r\n");
#endif
}

uint8_t imu_task_init(void){
    print("IMU task initing\r\n");
    onboard_imu_lib_init();
    return 1; // no error handler right now
}

void imu_task(void const *argu){
    int idle_period = IMU_DT * 1000;
    print("IDLE PERIOD: %d\r\n", idle_period);
    uint32_t imu_wake_time = osKernelSysTick();
    while (1) {
        onboard_imu_update();
        osDelayUntil(&imu_wake_time, idle_period);
    }
}
