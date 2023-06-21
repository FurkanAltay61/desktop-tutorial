/*
 * protimer_state_mach.c
 *
 *  Created on: Apr 7, 2022
 *      Author: furkan.altay
 */


#include "main.h"
#include "stdio.h"


//Prototypes of State Handlers

/*NOTE: State Handlers functions are defined as static because these functions are
 * only related to this file */


//static event_status_t protimer_state_handler_IDLE(protimer_t * const mobj,event_t const * const e);
//static event_status_t protimer_state_handler_TIME_SET(protimer_t * const mobj,event_t const * const e);
//static event_status_t protimer_state_handler_COUNTDOWN(protimer_t * const mobj,event_t const * const e);
//static event_status_t protimer_state_handler_PAUSE(protimer_t * const mobj,event_t const * const e);
//static event_status_t protimer_state_handler_STAT(protimer_t * const mobj,event_t const * const e);


//Prototype of Helper Functions

/*NOTE: Helper functions are defined as static because these functions are
 * only related to this file */

static void Display_Time(uint32_t time);
static void Display_Message(char *msg);
static void Display_Clear(char *msg );
static void Do_Beep(void);


void protimer_init(protimer_t *mobj){
	event_t ee;
	e_handler_t ehandler;

	ee.sig = ENTRY;
	mobj->active_state = IDLE;
	mobj->p_time = 0;
//	protimer_state_machine(mobj,&ee);
	ehandler = (e_handler_t)mobj->state_table[IDLE * MAX_SIGNALS + ENTRY];
//	if(ehandler)
//		(*ehandler)(mobj,&ee);
}


/* This function switch is for switching between different STATES */
/* Break statements are not used in functions switch statements
 * because we have to return status of the event handling*/

/* !!! IMPORTANT NOTE : mobj pointer content can be modified but mobj pointer(not content) cannot be modified
 * thats why "const" keyword is put before variable that pointer cannot be changed
 * mobj const pointer , pointing to variable data
 *
 * e pointer content cannot be modified as well as pointer cannot be modified
 * so "const" keyword put before variable and pointer operator that pointer cannot be changed.
 */


event_status_t IDLE_Entry(protimer_t * const mobj,event_t const * const e){
	mobj->c_time = 0;
	mobj->e_time = 0;
	Display_Message("Set Time:");
	Display_Time(0);
	return EVENT_HANDLED;
}

event_status_t IDLE_Exit(protimer_t * const mobj,event_t const * const e){
	Display_Clear("Display Cleared\n");
	return EVENT_HANDLED;
}

event_status_t IDLE_IncTime(protimer_t * const mobj,event_t const * const e){
	mobj->c_time += 60;
	mobj->active_state = TIME_SET;
	return EVENT_TRANSITION;
}

event_status_t IDLE_StartPause(protimer_t * const mobj,event_t const * const e){
	mobj->active_state = STAT;
	return EVENT_TRANSITION;
}

event_status_t IDLE_TimeTick(protimer_t * const mobj,event_t const * const e){

	if(((protimer_tick_event_t *)(e))->ss == 5){
		Do_Beep();
		return EVENT_HANDLED;
	}

	return EVENT_IGNORED;
}



event_status_t TIMESET_Entry(protimer_t * const mobj,event_t const * const e){
	Display_Time(mobj->c_time);
	return EVENT_HANDLED;
}

event_status_t TIMESET_Exit(protimer_t * const mobj,event_t const * const e){
	Display_Clear("Display Cleared\n");
	return EVENT_HANDLED;
}

event_status_t TIMESET_IncTime(protimer_t * const mobj,event_t const * const e){
	mobj->c_time += 60;
	Display_Time(mobj->c_time);
	return EVENT_HANDLED;
}

event_status_t TIMESET_DecTime(protimer_t * const mobj,event_t const * const e){
	if(mobj->c_time >= 60){
		mobj->c_time -=60;
		Display_Time(mobj->c_time);
		return EVENT_HANDLED;
	}
	return EVENT_IGNORED;
}

event_status_t TIMESET_Abort(protimer_t * const mobj,event_t const * const e){
	mobj->active_state = IDLE;
	return EVENT_TRANSITION;
}

event_status_t TIMESET_StartPause(protimer_t * const mobj,event_t const * const e){

	if(mobj->c_time >=60){
		mobj->active_state = COUNTDOWN;
		return EVENT_TRANSITION;
	}
	return EVENT_IGNORED;
}





event_status_t COUNTDOWN_Exit(protimer_t * const mobj,event_t const * const e){
	Display_Clear("Display Cleared\n");
	return EVENT_HANDLED;
}


event_status_t COUNTDOWN_TimeTick(protimer_t * const mobj,event_t const * const e){

	if(((protimer_tick_event_t *)(e))->ss == 10){
		 --mobj->c_time;
		 ++mobj->e_time;
		 Display_Time(mobj->c_time);

		 if(mobj->c_time == 0){
			 mobj->active_state = IDLE;
			 return EVENT_TRANSITION;
		 }

		return EVENT_HANDLED;
	}

	return EVENT_IGNORED;
}


event_status_t COUNTDOWN_StartPause(protimer_t * const mobj,event_t const * const e){
	mobj->active_state = PAUSE;
	return EVENT_TRANSITION;
}


event_status_t COUNTDOWN_Abort(protimer_t * const mobj,event_t const * const e){
	mobj->active_state = IDLE;
	return EVENT_TRANSITION;
}




event_status_t PAUSE_Entry(protimer_t * const mobj,event_t const * const e){
	Display_Message("Paused\n");
	return EVENT_HANDLED;
}

event_status_t PAUSE_Exit(protimer_t * const mobj,event_t const * const e){
	Display_Clear("Display Cleared\n");
	return EVENT_HANDLED;
}

event_status_t PAUSE_IncTime(protimer_t * const mobj,event_t const * const e){
	mobj->c_time += 60;
	mobj->active_state = TIME_SET;
	return EVENT_TRANSITION;
}

event_status_t PAUSE_DecTime(protimer_t * const mobj,event_t const * const e){
	if(mobj->c_time >= 60){
		mobj->c_time -=60;
		mobj->active_state = TIME_SET;
		return EVENT_TRANSITION;
	}
	return EVENT_IGNORED;
}

event_status_t PAUSE_Abort(protimer_t * const mobj,event_t const * const e){
	mobj->active_state = IDLE;
	return EVENT_TRANSITION;
}

event_status_t PAUSE_StartPause(protimer_t * const mobj,event_t const * const e){
	mobj->active_state = COUNTDOWN;
	return EVENT_TRANSITION;
}



event_status_t STAT_Entry(protimer_t * const mobj,event_t const * const e){
	Display_Time(mobj->p_time);
	Display_Message("Productive Time\n");
	return EVENT_HANDLED;
}

event_status_t STAT_Exit(protimer_t * const mobj,event_t const * const e){
	Display_Clear("Display Cleared\n");
	return EVENT_HANDLED;
}

event_status_t STAT_TimeTick(protimer_t * const mobj,event_t const * const e){
	static uint8_t tick_count;

	if(++tick_count == 30){
		tick_count = 0;
		mobj->active_state = IDLE;
		return EVENT_TRANSITION;
	}
	return EVENT_IGNORED;
}



////////////////////////////////helper functions/////////////////////////////////
static void Display_Time(uint32_t time){
	uint16_t m = time / 60;
	uint8_t  s = time % 60;
	printf("	%03d:%02d\n",m,s);
}

static void Display_Message(char *msg){
	printf("%s",msg);
	__NOP();
}

static void Display_Clear(char *msg ){
//	printf("%s",msg);
	__NOP();
}

static void Do_Beep(void){
	printf("Beeeeeeeep\n");
	__NOP();
}
