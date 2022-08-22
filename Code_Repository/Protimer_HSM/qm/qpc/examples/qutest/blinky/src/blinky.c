/*.$file${src::blinky.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: blinky.qm
* File:  ${src::blinky.c}
*
* This code has been generated by QM 5.1.0 <www.state-machine.com/qm/>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*.$endhead${src::blinky.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpc.h"
#include "blinky.h"
#include "bsp.h"

//Q_DEFINE_THIS_MODULE("blinky")

/*************** ask QM to declare the Blinky class ******************/
/*.$declare${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky} ..........................................................*/
typedef struct {
/* protected: */
    QActive super;

/* private: */
    QTimeEvt timeEvt;
} Blinky;

/* protected: */
static QState Blinky_initial(Blinky * const me, void const * const par);
static QState Blinky_off(Blinky * const me, QEvt const * const e);
static QState Blinky_on(Blinky * const me, QEvt const * const e);
/*.$enddecl${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

static Blinky l_blinky;

/*.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*. Check for the minimum required QP version */
#if (QP_VERSION < 680U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 6.8.0 or higher required
#endif
/*.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$define${AOs::AO_Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/* opaque pointer to the Blinky AO */
/*.${AOs::AO_Blinky} .......................................................*/
QActive * const AO_Blinky = &l_blinky.super;
/*.$enddef${AOs::AO_Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*************** ask QM to define the Blinky class  ******************/
/*.$define${AOs::Blinky_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky_ctor} .....................................................*/
void Blinky_ctor(void) {
    Blinky *me = &l_blinky;
    QActive_ctor(&me->super, Q_STATE_CAST(&Blinky_initial));
    QTimeEvt_ctorX(&me->timeEvt, &me->super, TIMEOUT_SIG, 0U);
}
/*.$enddef${AOs::Blinky_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*.$define${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky} ..........................................................*/
/*.${AOs::Blinky::SM} ......................................................*/
static QState Blinky_initial(Blinky * const me, void const * const par) {
    /*.${AOs::Blinky::SM::initial} */
    (void)par; /* unused parameter */

    QS_OBJ_DICTIONARY(&l_blinky);
    QS_OBJ_DICTIONARY(&l_blinky.timeEvt);

    QTimeEvt_armX(&me->timeEvt,
        BSP_TICKS_PER_SEC/2, BSP_TICKS_PER_SEC/2);

    QS_FUN_DICTIONARY(&Blinky_off);
    QS_FUN_DICTIONARY(&Blinky_on);

    return Q_TRAN(&Blinky_off);
}
/*.${AOs::Blinky::SM::off} .................................................*/
static QState Blinky_off(Blinky * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*.${AOs::Blinky::SM::off} */
        case Q_ENTRY_SIG: {
            BSP_ledOff();
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::off::TIMEOUT} */
        case TIMEOUT_SIG: {
            status_ = Q_TRAN(&Blinky_on);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*.${AOs::Blinky::SM::on} ..................................................*/
static QState Blinky_on(Blinky * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*.${AOs::Blinky::SM::on} */
        case Q_ENTRY_SIG: {
            BSP_ledOn();
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::on::TIMEOUT} */
        case TIMEOUT_SIG: {
            status_ = Q_TRAN(&Blinky_off);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*.$enddef${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
