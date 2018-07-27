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
 * @author  Alvin Sun
 * @date    2018-05-22
 * @file    task_test.h
 * @brief   RTOS task for testing library and bsp functionality (optional)
 */

#include "task_test.h"
#include "rm_test.h"

osThreadId      test_task_handle;

void test_task_create(void) {
    osThreadDef(testTask, test_task, osPriorityNormal, 0, 512);
    test_task_handle = osThreadCreate(osThread(testTask), NULL);
    if (test_task_handle == NULL)
        bsp_error_handler(__FUNCTION__, __LINE__, "test task create failed.");
}

void test_task(void const *argu) {
    while (1) {
        run_all_tests();
        osDelay(1000000);
    }
}

