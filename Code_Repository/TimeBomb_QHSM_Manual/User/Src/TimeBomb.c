/*
 * BlinkyButton.c
 *
 *  Created on: May 11, 2022
 *      Author: furkan.altay
 */


#include <TimeBomb.h>

//Q_DEFINE_THIS_MODULE("Timebomb");


QState TimeBomb_initial(TimeBomb * const me, QEvt const * const e);
QState TimeBomb_wait4button(TimeBomb * const me, QEvt const * const e);
QState TimeBomb_blink(TimeBomb * const me, QEvt const * const e);
QState TimeBomb_pause(TimeBomb * const me, QEvt const * const e);
QState TimeBomb_boom(TimeBomb * const me, QEvt const * const e);
QState TimeBomb_armed(TimeBomb * const me, QEvt const * const e);
QState TimeBomb_defused(TimeBomb * const me, QEvt const * const e);

void TimeBomb_ctor(TimeBomb * const me) {
    QActive_ctor(&me->super, (QStateHandler)&TimeBomb_initial);
    QTimeEvt_ctorX(&me->te,&me->super,TIMEOUT_SIG,0U);
}



QState TimeBomb_initial(TimeBomb * const me, QEvt const * const e) {
	return Q_TRAN(TimeBomb_wait4button);
}


QState TimeBomb_armed(TimeBomb * const me, QEvt const * const e){
	QState Status;

	switch(e->sig){
		case Q_EXIT_SIG:{
			BspLed1Off();
			BspLed2Off();
			BspLed3Off();
			Status = Q_HANDLED();
			break;
		}
		case Q_INIT_SIG:{
			Status = Q_TRAN(TimeBomb_wait4button);
		}
		case BUTTON2_PRESSED_SIG:{
			Status = Q_TRAN(TimeBomb_defused);
			break;
		}
		default:{
			Status = Q_SUPER(QHsm_top);
			break;
		}
	}

	return Status;
}

QState TimeBomb_wait4button(TimeBomb * const me, QEvt const * const e){
	QState Status;

	switch(e->sig){
		case Q_ENTRY_SIG:{
			BspLed1On();
			Status = Q_HANDLED();
			break;
		}
		case Q_EXIT_SIG:{
			BspLed1Off();
			Status = Q_HANDLED();
			break;
		}
		case BUTTON_PRESSED_SIG:{
			me->blink_cntr = 3U;
			Status =Q_TRAN(TimeBomb_blink);
			break;
		}
		default:{
//			Status = IGNORED_STATUS;
			Status = Q_SUPER(TimeBomb_armed);
			break;
		}
	}

	return Status;
}


QState TimeBomb_blink(TimeBomb * const me, QEvt const * const e) {

	QState Status;

	switch(e->sig){
		case Q_ENTRY_SIG:{
			BspLed2On();
			QTimeEvt_armX(&me->te,BSP_TICKS_PER_SEC/2,0U);
			Status = Q_HANDLED();
			break;
		}
		case Q_EXIT_SIG:{
			BspLed2Off();
			Status = Q_HANDLED();
			break;
		}
		case TIMEOUT_SIG:{
			Status = Q_TRAN(TimeBomb_pause);
			break;
		}
		default:{
//			Status = IGNORED_STATUS;
			Status = Q_SUPER(TimeBomb_armed);
			break;
		}
	}

	return Status;
}



QState TimeBomb_pause(TimeBomb * const me, QEvt const * const e){


	QState Status;

	switch(e->sig){
		case Q_ENTRY_SIG:{
			QTimeEvt_armX(&me->te,BSP_TICKS_PER_SEC/2,0U);
			Status = Q_HANDLED();
			break;
		}
		case TIMEOUT_SIG:{
			--me->blink_cntr;
			if(me->blink_cntr > 0U){
				Status = Q_TRAN(TimeBomb_blink);
			}
			else{
				Status = Q_TRAN(TimeBomb_boom);
			}
			break;
		}
		default:{
//			Status = IGNORED_STATUS;
			Status = Q_SUPER(TimeBomb_armed);
			break;
		}
	}

	return Status;
}


QState TimeBomb_boom(TimeBomb * const me, QEvt const * const e){


	QState Status;

	switch(e->sig){
		case Q_ENTRY_SIG:{
			BspLed1On();
			BspLed2On();
			BspLed3On();
			Status = Q_HANDLED();
			break;
		}
		default:{
//			Status = IGNORED_STATUS;
			Status = Q_SUPER(TimeBomb_armed);
			break;
		}
	}

	return Status;
}


QState TimeBomb_defused(TimeBomb * const me, QEvt const * const e){
	QState Status;

	switch(e->sig){
		case Q_ENTRY_SIG:{
			BspLed1Off();
			BspLed2On();
			BspLed3Off();
			Status = Q_HANDLED();
			break;
		}
		case BUTTON2_PRESSED_SIG:{
			Status = Q_TRAN(TimeBomb_armed);
			break;
		}
		default:{
			Status = Q_SUPER(QHsm_top);
			break;
		}
	}

	return Status;
}





