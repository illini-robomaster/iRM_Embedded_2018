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
 * @date    2018-04-21
 * @file    task_referee.c
 * @brief   RTOS task fro referee tx and rx
 * @log     2018-04-21 nickelliang
 */

#include "task_referee.h"

static osMutexId        referee_rx_mutex;
static osMutexId        referee_tx_mutex;
static osEvent          referee_event;

osThreadId      referee_task_handle;

void referee_task_create(void) {
    osThreadDef(refereeTask, referee_task, osPriorityNormal, 0, 4096);
    referee_task_handle = osThreadCreate(osThread(refereeTask), NULL);
    if (referee_task_handle == NULL)
        bsp_error_handler(__FUNCTION__, __LINE__, "Referee task failed to create.");
}

uint8_t referee_task_init(void) {
    /* Create rx mutex */
    osMutexDef(referee_rx_mutex);
    referee_rx_mutex = osMutexCreate(osMutex(referee_rx_mutex));
    /* Create tx mutex */
    osMutexDef(referee_tx_mutex);
    referee_tx_mutex = osMutexCreate(osMutex(referee_tx_mutex));
    /* Initialize data process instance */
    referee_process = data_process_init(&REFEREE_PORT, referee_rx_mutex, REFEREE_FIFO_SIZE, REFEREE_BUFF_SIZE, REFEREE_SOF, referee_dispatcher, &referee_info, referee_tx_mutex, referee_packer);
    if (NULL == referee_process) {
        bsp_error_handler(__FUNCTION__, __LINE__, "Referee data process instance initialization failed.");
        return 0;
    }
    if (!referee_init(referee_process)) {
        bsp_error_handler(__FUNCTION__, __LINE__, "Referee UART hardware initialization failed.");
        return 0;
    }
    return 1;
}

void referee_task(void const *argu) {
    while (!referee_task_init()) {
        bsp_error_handler(__FUNCTION__, __LINE__, "Referee task failed to init.");
    }
    while (1) {
#ifdef DEBUG
        BSP_DEBUG;
        print("In referee task loop.\r\n");
#endif
        referee_event = osSignalWait(REFEREE_RX_SIGNAL | REFEREE_TX_SIGNAL, osWaitForever);
        if (referee_event.status == osEventSignal) {
            if (referee_event.value.signals & REFEREE_RX_SIGNAL) {
#ifdef DEBUG
                BSP_DEBUG;
                print("Rx signal received.\r\n");
#endif
                data_process_rx(referee_process);
            }
            if (referee_event.value.signals & REFEREE_TX_SIGNAL) {
#ifdef DEBUG
                BSP_DEBUG;
                print("Tx signal received.\r\n");
#endif
                data_process_tx(referee_process);
            }
        }
    }
}

/**
 * Callback function declared in referee.c. This is a weak function.
 *
 * @author Nickel_Liang
 * @date   2018-05-23
 */
void referee_incomming() {
    osSignalSet(referee_task_handle, REFEREE_RX_SIGNAL);
}

/**
 * Forward function declared in referee.c. This is a weak function.
 *
 * @author Nickel_Liang
 * @date   2018-05-26
 */
void referee_outgoing() {
    osSignalSet(referee_task_handle, REFEREE_TX_SIGNAL);
}
