#include "task_shoot.h"
#include "dbus.h"
#include "referee.h"

static osEvent      shoot_event;

osThreadId  shoot_task_handle;

void shoot_task_create(void) {
    osThreadDef(shootTask, shoot_task, osPriorityNormal, 0, 256);
    shoot_task_handle = osThreadCreate(osThread(shootTask), NULL);
    if (shoot_task_handle == NULL)
        bsp_error_handler(__FUNCTION__, __LINE__, "Shoot task failed to create.");
}

/* TODO: Poker API changes, require poker_run, to be fixed */
static void keyboard_shoot(shooter_t *my_shooter, dbus_t *rc) {
    if (rc->key.bit.C)
        flywhl_on(my_shooter);
    if (rc->key.bit.V)
        flywhl_off(my_shooter);
    if (rc->mouse.l && 
            my_shooter->flywhl->state == FLYWHL_ON &&
            referee_info.power_heat_data.barrel_heat_17 < 10) {
        my_shooter->poker->motor->out = -7000;
    }
    else {
        poker_set_speed(my_shooter, 0);
    }
    poker_run(my_shooter);
    osDelay(5);
}

static void remote_shoot(shooter_t *my_shooter, dbus_t *rc) {
    if (rc->swr != RC_SWITCH_DN) {
        flywhl_on(my_shooter);
        if (rc->swr == RC_SWITCH_UP && referee_info.power_heat_data.barrel_heat_17 < 30)
            my_shooter->poker->motor->out = -7500;
        else
            poker_set_speed(my_shooter, 0);
    }
    else {
        flywhl_off(my_shooter);
        poker_set_speed(my_shooter, 0);
        my_shooter->poker->integrator = 0;
    }
    poker_run(my_shooter);
    osDelay(5);
}

void shoot_task(void const *argu) {
    /* initialization*/
    shooter_t *my_shooter = shooter_init(NULL, PWM);
    dbus_t *rc = dbus_get_struct();
    osDelay(5000);
    /* task loop */
    while (1) {
        if (rc->swr != RC_SWITCH_DN)
            remote_shoot(my_shooter, rc);
        else
            keyboard_shoot(my_shooter, rc);
    }
}
