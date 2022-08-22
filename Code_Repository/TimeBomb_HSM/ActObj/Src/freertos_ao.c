/*****************************************************************************
* Active Object pattern implementation based on uC/OS-II (uC/AO)
*
*                    Q u a n t u m  L e a P s
*                    ------------------------
*                    Modern Embedded Software
*
* Copyright (C) 2020 Quantum Leaps, LLC. All rights reserved.
*
* SPDX-License-Identifier: APACHE-2.0
*
* This software is distributed by Quantum Leaps, LLC under the terms of
* Apache License Version 2.0, which is the same license used for uC/OS-II RTOS.
* The text of the license is available at: www.apache.org/licenses/LICENSE-2.0.
*
* Contact information:
* <www.state-machine.com>
* <info@state-machine.com>
*****************************************************************************/
#include <freertos_ao.h> /* uC/AO interface */



static Event const entryEvt = { ENTRY_SIG};
static Event const exitEvt = { EXIT_SIG};

void Hsm_ctor(Hsm * const me,StateHandler initial){
	me->State = initial;
}
void Hsm_init(Hsm * const me, Event const * const e){

	Q_ASSERT(me->State != (StateHandler)0);
	(*me->State)(me,e);
	(*me->State)(me,&entryEvt);

}

void Hsm_dispatch(Hsm * const me, Event const * const e){
	State Stat;
	StateHandler prev_state = me->State;

//	Q_ASSERT(me->State != (StateHandler)0 && (e->sig < MAX_SIG));
	Stat = (*me->State)(me,e);

	while(Stat == SUPER_STATUS){
		Stat = (*me->temp)(me,e);
	}

	if(Stat == TRAN_STATUS){
		(*prev_state)(me,&exitEvt);
		(*me->State)(me,&entryEvt);
	}
}

State Hsm_top(Hsm * const me, Event const * const e){
	return IGNORED_STATUS;
}


/*..........................................................................*/
void Active_ctor(Active * const me, StateHandler initial) {
	Hsm_ctor(&me->super,initial);
}

/*..........................................................................*/
/* Thread function for all Active Objects (uC/OS-II task signature) */
static void Active_eventLoop(void *pdata) {
    Active *me = (Active *)pdata; /* the AO instance "me" */

    /*initialise the AO*/
    Hsm_init(&me->super,(Event *)0);

    /* event loop ("message pump") */
    while (1) {
        Event *e; /* pointer to event object ("message") */

        /*new*/
        if(xQueueReceive(*me->queue,(void *)&e,(TickType_t)0) == pdPASS){
			/* dispatch event to the active object 'me' */
        	Hsm_dispatch(&me->super, e);
        }

    }
}

/*..........................................................................*/
void Active_start(Active * const me,
		  	  	  const uint32_t ulStackDepth,
				  UBaseType_t uxPriority,
				  StackType_t * const puxStackBuffer,
				  StaticTask_t * const pxTaskBuffer,
				  Event **queueSto,
				  const UBaseType_t uxQueueLength)
{

    /* precondition */
    Q_ASSERT(me /* AO instance must be provided (cannot be NULL) */
             && (0 < uxPriority) && (uxPriority < configLIBRARY_LOWEST_INTERRUPT_PRIORITY - 2U));

    *me->queue = xQueueCreate(uxQueueLength,sizeof((void**)queueSto));
    Q_ASSERT(*me->queue); /* queue must be created */

    me->thread = configLIBRARY_LOWEST_INTERRUPT_PRIORITY - 2U - uxPriority; /* uC/OS-II priority */

   xTaskCreateStatic(Active_eventLoop,"x", ulStackDepth,(void *)me, me->thread, puxStackBuffer, pxTaskBuffer);
}

/*..........................................................................*/
void Active_post(Active * const me, Event const * const e) {
	BaseType_t xQueueWoken = pdFALSE;
	xQueueSendFromISR(*me->queue, (void *)&e,&xQueueWoken);
	portYIELD_FROM_ISR(xQueueWoken);
}

/*--------------------------------------------------------------------------*/
/* Time Event services... */

static TimeEvent *l_tevt[10]; /* all TimeEvents in the application */
static uint_fast8_t l_tevtNum; /* current number of TimeEvents */

/*..........................................................................*/
void TimeEvent_ctor(TimeEvent * const me, Signal sig, Active *act) {
#if OS_CRITICAL_METHOD == 3
    OS_CPU_SR  cpu_sr;
#endif

    /* no critical section because it is presumed that all TimeEvents
    * are created *before* multitasking has started.
    */
    me->super.sig = sig;
    me->act = act;
    me->timeout = 0U;
    me->interval = 0U;

    /* register one more TimeEvent instance */
    taskENTER_CRITICAL();
    Q_ASSERT(l_tevtNum < sizeof(l_tevt)/sizeof(l_tevt[0]));
    l_tevt[l_tevtNum] = me;
    ++l_tevtNum;
    taskEXIT_CRITICAL();
}

/*..........................................................................*/
void TimeEvent_arm(TimeEvent * const me, uint32_t timeout, uint32_t interval) {
    taskENTER_CRITICAL();
    me->timeout = timeout;
    me->interval = interval;
    taskEXIT_CRITICAL();
}

/*..........................................................................*/
void TimeEvent_disarm(TimeEvent * const me) {
    taskENTER_CRITICAL();
    me->timeout = 0U;
    taskEXIT_CRITICAL();
}

/*..........................................................................*/
void TimeEvent_tick(void) {
    uint_fast8_t i;
    for (i = 0U; i < l_tevtNum; ++i) {
        TimeEvent * const t = l_tevt[i];
        Q_ASSERT(t); /* TimeEvent instance must be registered */
        if (t->timeout > 0U) { /* is this TimeEvent armed? */
            if (--t->timeout == 0U) { /* is it expiring now? */
                Active_post(t->act, &t->super);
                t->timeout = t->interval; /* rearm or disarm (one-shot) */
           }
        }
    }
}



