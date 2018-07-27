#ifndef _TASK_SHOOT_H_
#define _TASK_SHOOT_H_

#include "shooter.h"
#include "cmsis_os.h"
#include "bsp_error_handler.h"

#define POKER_STOP_SIGNAL   (1 << 0)

extern osThreadId shoot_task_handle;

void shoot_task_create(void);

void shoot_task(const void *argu);

#endif
