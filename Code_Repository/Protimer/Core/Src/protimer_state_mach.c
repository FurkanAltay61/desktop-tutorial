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


static event_status_t protimer_state_handler_IDLE(protimer_t * const mobj,event_t const * const e);
static event_status_t protimer_state_handler_TIME_SET(protimer_t * const mobj,event_t const * const e);
static event_status_t protimer_state_handler_COUNTDOWN(protimer_t * const mobj,event_t const * const e);
static event_status_t protimer_state_handler_PAUSE(protimer_t * const mobj,event_t const * const e);
static event_status_t protimer_state_handler_STAT(protimer_t * const mobj,event_t const * const e);


//Prototype of Helper Functions

/*NOTE: Helper functions are defined as static because these functions are
 * only related to this file */

static void Display_Time(uint32_t time);
static void Display_Message(char *msg);
static void Display_Clear(char *msg );
static void Do_Beep(void);


void protimer_init(protimer_t *mobj){
	event_t ee;
	ee.sig = ENTRY;
	mobj->active_state = IDLE;
	mobj->p_time = 0;
	protimer_state_machine(mobj,&ee);
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

event_status_t protimer_state_machine(protimer_t * const mobj,event_t const * const e){

	switch(mobj->active_state){

		case IDLE:
			return protimer_state_handler_IDLE(mobj,e);

		case TIME_SET:
			return protimer_state_handler_TIME_SET(mobj,e);

		case COUNTDOWN:
			return protimer_state_handler_COUNTDOWN(mobj,e);

		case PAUSE:
			return protimer_state_handler_PAUSE(mobj,e);

		case STAT:
			return protimer_state_handler_STAT(mobj,e);

	}

	return EVENT_IGNORED;
}


/* These functions switch's are for switching between different SIGNALS */
static event_status_t protimer_state_handler_IDLE(protimer_t * const mobj,event_t const * const e){

	switch(e->sig){

		case ENTRY:{
			mobj->c_time = 0;
			mobj->e_time = 0;
			Display_Message("Set Time:");
			Display_Time(0);
			return EVENT_HANDLED;
		}

		case EXIT:{
			Display_Clear("Display Cleared\n");
			return EVENT_HANDLED;
		}

		case INC_TIME:{
			mobj->c_time += 60;
			mobj->active_state = TIME_SET;
			return EVENT_TRANSITION;
		}

		case START_PAUSE:{
			mobj->active_state = STAT;
			return EVENT_TRANSITION;
		}

		case TIME_TICK:{

			if(((protimer_tick_event_t *)(e))->ss == 5){
				Do_Beep();
				return EVENT_HANDLED;
			}

			return EVENT_IGNORED;
		}

	}//End Of Switch Statement

	return EVENT_IGNORED;

}

static event_status_t protimer_state_handler_TIME_SET(protimer_t * const mobj,event_t const * const e){

	switch(e->sig){

		case ENTRY:{
			Display_Time(mobj->c_time);
			return EVENT_HANDLED;
		}

		case EXIT:{
			Display_Clear("Display Cleared\n");
			return EVENT_HANDLED;
		}

		case INC_TIME:{
			mobj->c_time += 60;
			Display_Time(mobj->c_time);
			return EVENT_HANDLED;
		}

		case DEC_TIME:{
			if(mobj->c_time >= 60){
				mobj->c_time -=60;
				Display_Time(mobj->c_time);
				return EVENT_HANDLED;
			}
			return EVENT_IGNORED;
		}

		case ABRT:{
			mobj->active_state = IDLE;
			return EVENT_TRANSITION;
		}

		case START_PAUSE:{
			if(mobj->c_time >=60){
				mobj->active_state = COUNTDOWN;
				return EVENT_TRANSITION;
			}

			return EVENT_IGNORED;

		}


	}//End Of Switch Statement

	return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_COUNTDOWN(protimer_t * const mobj,event_t const * const e){

	switch(e->sig){

		case EXIT:{
			mobj->p_time += mobj->e_time;
			mobj->e_time = 0;
			return EVENT_HANDLED;
		}

		case TIME_TICK:{
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

		case START_PAUSE:{
			mobj->active_state = PAUSE;
			return EVENT_TRANSITION;
		}

		case ABRT:{
			mobj->active_state = IDLE;
			return EVENT_TRANSITION;
		}

	}//End Of Switch Statement

	return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_PAUSE(protimer_t * const mobj,event_t const * const e){

	switch(e->sig){

		case ENTRY:{
			Display_Message("Paused\n");
			return EVENT_HANDLED;
		}

		case EXIT:{
			Display_Clear("Display Cleared\n");
			return EVENT_HANDLED;
		}

		case INC_TIME:{
			mobj->c_time += 60;
			mobj->active_state = TIME_SET;
			return EVENT_TRANSITION;
		}

		case DEC_TIME:{
			if(mobj->c_time >= 60){
				mobj->c_time -=60;
				mobj->active_state = TIME_SET;
				return EVENT_TRANSITION;
			}
			return EVENT_IGNORED;
		}

		case START_PAUSE:{
			mobj->active_state = COUNTDOWN;
			return EVENT_TRANSITION;
		}

		case ABRT:{
			mobj->active_state = IDLE;
			return EVENT_TRANSITION;
		}

	}//End Of Switch Statement

	return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_STAT(protimer_t * const mobj,event_t const * const e){

	static uint8_t tick_count;

	switch(e->sig){

		case ENTRY:{
			Display_Time(mobj->p_time);
			Display_Message("Productive Time\n");
			return EVENT_HANDLED;
		}

		case EXIT:{
			Display_Clear("Display Cleared\n");
			return EVENT_HANDLED;
		}


		case TIME_TICK:{
//			if(((protimer_tick_event_t *)(e))->ss == 10){
//				mobj->active_state = IDLE;
//				return EVENT_TRANSITION;
//			}

			if(++tick_count == 30){
				tick_count = 0;
				mobj->active_state = IDLE;
				return EVENT_TRANSITION;
			}

			return EVENT_IGNORED;
		}


	}//End Of Switch Statement

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