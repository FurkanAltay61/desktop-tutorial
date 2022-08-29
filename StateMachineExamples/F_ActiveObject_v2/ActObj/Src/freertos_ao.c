
#include "freertos_ao.h" /* FreeRTOS/AO Interface */

static char const this_module[] = "freertos_ao"; /* this module name for Q_ASSERT() */


/*********************************************************************
 * @fn      		  - Active_ctor
 *
 * @brief             -	Active Object Constructor Function
 *
 * @param_type		  - Active 	 		: Active Pointer Structure
 * @param_name	      -	me 		 		: Active Object me pointer
 *
 * @param_type		  - DispatchHandler : DispatchHandler Structure
 * @param_name        - dispatch 		: Active Object Dispatch Handler
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of Active Structure
 */

void Active_ctor(Active * const me, DispatchHandler dispatch) {
    me->dispatch = dispatch; /* attach the dispatch handler for the "me" AO */
}


/*********************************************************************
 * @fn      		  - Active_eventLoop
 *
 * @brief             -	Active Object Event Loop Function
 *
 * @param_type		  - void *	 		: This declaration does not have any type, which means that it can be any type
 * @param_name	      -	pdata 		    : function parameter
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of Active Structure
 */

static void Active_eventLoop(void *pdata) {
	 Active *me = (Active *)pdata; /* Function parameter is  assigned to Active Object me pointer.*/


    static Event const initEvt = { INIT_SIG };	/*The initial event has been created */
    (*me->dispatch)(me, &initEvt);				/*The initial event is dispatched */

    /* event loop ("message pump") */
    while (1) {
        Event *e; /* pointer to event object ("message") */

        /*Dispatch the received event , if there is */
        /* if there is an event in the queue , xqueuereceive function returns pdpass value */
        if(xQueueReceive(me->queue,(void *)&e,(TickType_t)portMAX_DELAY) == pdPASS){
			/* dispatch event to the active object 'me' */
			(*me->dispatch)(me, e); /* NO BLOCKING! */
        }

    }
}

/*********************************************************************
 * @fn      		  - Active_start
 *
 * @brief             -	Active Object Start Function
 *
 * @param_type		  - Active * const		: Active Pointer Structure with const prefix
 * @param_name	      -	me 					: Active Object me pointer
 *
 * @param_type		  - const char * const	: const char pointer
 * @param_name	      -	ActObjName 			: Active Object Name
 *
 *
 * @param_type        - uint32_t			: -
 * @param_name		  -	ulStackDepth		: Active Object Task Stack Size
 *
 * @param_type		  - UBaseType_t			: Unsigned Long
 * @param_name		  -	uxPriority		    : Active Object Task Priority
 *
 * @param_type		  - StackType_t			: uint32_t
 * @param_name		  -	puxStackBuffer		: Active Object Stack Buffer
 *
 * @param_type		  - StaticTask_t		: Task Control Block Structure
 * @param_name		  -	pxTaskBuffer		: Active Object Task Buffer
 *
 * @param_type		  - Event				: Event Structure
 * @param_name		  -	queueSto		 	: Active Object Event Queue
 *
 * @param_type		  -	UBaseType_t			: Unsigned Long
 * @param_name		  - uxQueueLength		: Active Object Queue Length
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of Active Structure
 */
void Active_start(Active * const me,
				  const char * const ActObjName,
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

    /*Event queue is created to hold messages*/
    me->queue = xQueueCreate(uxQueueLength,sizeof((void**)queueSto));

    if(me->queue == NULL) {return;} /*Return, if queue creation is failed */

    Q_ASSERT(me->queue); /* queue must be created */

    //me->thread = configLIBRARY_LOWEST_INTERRUPT_PRIORITY - 2U - uxPriority; /* uC/OS-II priority */
    me->thread = uxPriority;

   xTaskCreateStatic(Active_eventLoop,ActObjName, ulStackDepth,(void *)me, me->thread, puxStackBuffer, pxTaskBuffer);
}


/*********************************************************************
 * @fn      		  - Active_post
 *
 * @brief             -	Active Object Event Post Function
 *
 * @param_type		  - Active 	 		: Active Pointer Structure
 * @param_name	      -	me 		 		: Active Object me pointer
 *
 * @param_type		  - Event 			: Active Object Event Enumarator
 * @param_name        - e 				: Active Object e pointer
 *
 * @return            - void
 *
 * @Note              - This function write event to the event queue & post it to the dispatch function.
 */
void Active_post(Active * const me, Event const * const e) {
	BaseType_t xQueueWoken = pdFALSE;
	xQueueSendFromISR(me->queue, (void *)&e,&xQueueWoken);
	portYIELD_FROM_ISR(xQueueWoken);
}

/*--------------------------------------------------------------------------*/
/* Time Event services... */

static TimeEvent *l_tevt[10]; /* all TimeEvents in the application */
static uint_fast8_t l_tevtNum; /* current number of TimeEvents */


/*********************************************************************
 * @fn      		  - TimeEvent_ctor
 *
 * @brief             -	Time Event Constructor Function
 *
 * @param_type		  - TimeEvent 	 	: TimeEvent Pointer Structure
 * @param_name	      -	me 		 		: TimeEvent me pointer
 *
 * @param_type		  - Signal 			: Signal Structure
 * @param_name        - sig 			: Signal Structure sig variable
 *
 * @param_type		  - Active 			: Active Pointer Structure
 * @param_name        - act 			: Active Pointer Structure variable
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of TimeEvent Structure
 */
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

/*********************************************************************
 * @fn      		  - TimeEvent_arm
 *
 * @brief             -	Time Event Arming Function
 *
 * @param_type		  - TimeEvent 	 	: TimeEvent Pointer Structure
 * @param_name	      -	me 		 		: TimeEvent me pointer
 *
 * @param_type		  - uint32_t 		: -
 * @param_name        - timeout 		: Timeout Value
 *
 * @param_type		  - uint32_t 		: -
 * @param_name        - interval 		: Timeout Interval Value
 *
 * @return            - void
 *
 * @Note              - This function starts a created timer event.
 */
void TimeEvent_arm(TimeEvent * const me, uint32_t timeout, uint32_t interval) {
    taskENTER_CRITICAL();
    me->timeout = timeout;
    me->interval = interval;
    taskEXIT_CRITICAL();
}

/*********************************************************************
 * @fn      		  - TimeEvent_disarm
 *
 * @brief             -	Time Event Disarming Function
 *
 * @param_type		  - TimeEvent 	 	: TimeEvent Pointer Structure
 * @param_name	      -	me 		 		: TimeEvent me pointer
 *
 * @return            - void
 *
 * @Note              - This function stops a created timer event
 */
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

