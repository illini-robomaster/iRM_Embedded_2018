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
 * @date    2018-05-22
 * @file    task_tx2.c
 * @brief   RTOS task for TX2(PC) tx and rx
 * @log     2018-05-22 nickelliang
 */

#include "task_tx2.h"

static osMutexId        tx2_rx_mutex;
static osMutexId        tx2_tx_mutex;
static osEvent          tx2_event;

data_process_t  *tx2_process;
tx2_t           tx2_info;
osThreadId      tx2_task_handle;

void tx2_task_create(void) {
    osThreadDef(tx2Task, tx2_task, osPriorityNormal, 0, 512);
    tx2_task_handle = osThreadCreate(osThread(tx2Task), NULL);
    if (tx2_task_handle == NULL)
        bsp_error_handler(__FUNCTION__, __LINE__, "TX2 task create failed.");
}

uint8_t tx2_task_init(void) {
    /* Create rx mutex */
    osMutexDef(tx2_rx_mutex);
    tx2_rx_mutex = osMutexCreate(osMutex(tx2_rx_mutex));
    osMutexDef(tx2_tx_mutex);
    tx2_tx_mutex = osMutexCreate(osMutex(tx2_tx_mutex));
    /* Initialize data process instance */
    tx2_process = data_process_init(&TX2_PORT, tx2_rx_mutex, TX2_FIFO_SIZE,
            TX2_BUFF_SIZE, TX2_SOF, tx2_dispatcher, &tx2_info, tx2_tx_mutex, tx2_packer);
    if (tx2_process == NULL) {
        bsp_error_handler(__FUNCTION__, __LINE__, "TX2 data process instance initialization failed.");
        return 0;
    }
    if (!tx2_init(tx2_process)) {
        bsp_error_handler(__FUNCTION__, __LINE__, "TX2 UART hardware initialization failed.");
        return 0;
    }
    return 1;
}

void tx2_task(void const *argu) {
    while (!tx2_task_init()) {
        bsp_error_handler(__FUNCTION__, __LINE__, "TX2 task failed to init.");
    }
    while (1) {
#ifdef DEBUG
        BSP_DEBUG;
        print("In tx2 task loop.\r\n");
#endif
        tx2_event = osSignalWait(TX2_RX_SIGNAL | TX2_TX_SIGNAL, osWaitForever);
        if (tx2_event.status == osEventSignal) {
            if (tx2_event.value.signals & TX2_RX_SIGNAL) {
#ifdef DEBUG
                BSP_DEBUG;
                print("Rx signal received.\r\n");
#endif
                data_process_rx(tx2_process);
            }
            if (tx2_event.value.signals & TX2_TX_SIGNAL) {
#ifdef DEBUG
                BSP_DEBUG;
                print("Tx signal received.\r\n");
#endif
                data_process_tx(tx2_process);
            }
        }
    }
}

/**
 * Callback function declared in tx2.c. This is a weak function.
 *
 * @author Nickel_Liang
 * @date   2018-05-23
 */
void tx2_incomming() {
    osSignalSet(tx2_task_handle, TX2_RX_SIGNAL);
}

/**
 * Forward function declared in tx2.c. This is a weak function.
 *
 * @author Nickel_Liang
 * @date   2018-05-26
 */
void tx2_outgoing(void) {
    osSignalSet(tx2_task_handle, TX2_TX_SIGNAL);
}
