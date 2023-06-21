


#ifndef FREERTOS_AO_H
#define FREERTOS_AO_H

#include "FreeRTOS.h"  															       /* uC/OS-II API, port and compile-time configuration */
#include "queue.h"

/*---------------------------------------------------------------------------*/
/* Event facilities... */

typedef uint16_t Signal; 																/* event signal */

enum ReservedSignals {
    INIT_SIG, 																			/* dispatched to AO before entering event-loop */
    USER_SIG  																			/* first signal available to the users */
};

/* Event base class */
typedef struct {
    Signal sig; 																		/* event signal */
    																					/* event parameters added in subclasses of Event */
} Event;

/*---------------------------------------------------------------------------*/
/* Actvie Object facilities... */

typedef struct Active Active; 															/* forward declaration */

typedef void (*DispatchHandler)(Active * const me, Event const * const e);				/*Dispatch Handler Pointer Function*/

/* Active Object base class */
struct Active {
    uint8_t thread;     																/* private thread (the unique uC/OS-II task priority) */
    QueueHandle_t queue;  															    /* private message queue */
    DispatchHandler dispatch; 															/* pointer to the dispatch() function */

    /* active object data added in subclasses of Active */
};


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

void Active_ctor(Active * const me, 													/*Active Object me pointer */
				 DispatchHandler dispatch);												/*Active Object Dispatch Handler*/

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
void Active_start(Active * const me,													/*Active Object me pointer */
				  const char * const ActObjName,										/*Active Object Name*/
		  	  	  const uint32_t ulStackDepth,											/*Active Object Task Stack Size*/
				  UBaseType_t uxPriority,												/*Active Object Task Priority*/
				  StackType_t * const puxStackBuffer,									/*Active Object Stack Buffer*/
				  StaticTask_t * const pxTaskBuffer,									/*Active Object Task Buffer*/
				  Event **queueSto,														/*Active Object Event Queue*/
				  const UBaseType_t uxQueueLength);										/*Active Object Queue Length*/


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

void Active_post(Active * const me,														/*Active Object me pointer */
				 Event const * const e);												/*Active Object Event Enum*/

/*---------------------------------------------------------------------------*/
/* Time Event facilities... */

/* Time Event class */
typedef struct {
    Event super;       /* inherit Event */
    Active *act;       /* the AO that requested this TimeEvent */
    uint32_t timeout;  /* timeout counter; 0 means not armed */
    uint32_t interval; /* interval for periodic TimeEvent, 0 means one-shot */
} TimeEvent;



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

void TimeEvent_ctor(TimeEvent * const me, Signal sig, Active *act);


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
void TimeEvent_arm(TimeEvent * const me, uint32_t timeout, uint32_t interval);


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
void TimeEvent_disarm(TimeEvent * const me);

/* static (i.e., class-wide) operation */
void TimeEvent_tick(void);

/*---------------------------------------------------------------------------*/
/* Assertion facilities... */

#define Q_ASSERT(check_)                   \
    if (!(check_)) {                       \
        Q_onAssert(this_module, __LINE__); \
    } else (void)0

void Q_onAssert(char const *module, int loc);

#endif /* UC_AO_H */
