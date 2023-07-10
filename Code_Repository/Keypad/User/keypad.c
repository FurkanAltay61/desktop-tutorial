/*$file${.::keypad.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: blinky_console.qm
* File:  ${.::keypad.c}
*
* This code has been generated by QM 5.2.5 <www.state-machine.com/qm>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* SPDX-License-Identifier: GPL-3.0-or-later
*
* This generated code is open source software: you can redistribute it under
* the terms of the GNU General Public License as published by the Free
* Software Foundation.
*
* This code is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* NOTE:
* Alternatively, this generated code may be distributed under the terms
* of Quantum Leaps commercial licenses, which expressly supersede the GNU
* General Public License and are specifically designed for licensees
* interested in retaining the proprietary status of their code.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*/
/*$endhead${.::keypad.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpc.h"
#include "bsp.h"
#include "keypad.h"
#include "my_mpu6050.h"

extern mpu6050 myMpu;
extern I2C_HandleTypeDef hi2c1;

static char keypad[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

static uint8_t  LastButtonStateArr[4][3]={0};
static uint32_t prevTick[4][3]= {0};
static uint16_t RowArr[4] = {GPIO_PIN_9,GPIO_PIN_11,GPIO_PIN_13,GPIO_PIN_15};
static uint16_t ColArr[3] = {GPIO_PIN_11,GPIO_PIN_13,GPIO_PIN_15};
static char Str[30]={0};
static uint8_t chr=0,start=0;
static char PressedKey;

/*$declare${AOs::Keypad} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${AOs::Keypad} ...........................................................*/
typedef struct {
/* protected: */
    QActive super;

/* private: */
    QTimeEvt timeEvt;
} Keypad;

/* protected: */
static QState Keypad_initial(Keypad * const me, void const * const par);
static QState Keypad_System(Keypad * const me, QEvt const * const e);
static QState Keypad_Button(Keypad * const me, QEvt const * const e);
/*$enddecl${AOs::Keypad} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/* instantiate the Blinky active object ------------------------------------*/
static Keypad l_keypad;
QActive * const AO_Keypad = &l_keypad.super;

/*$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/* Check for the minimum required QP version */
#if (QP_VERSION < 700U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.0.0 or higher required
#endif
/*$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*$define${AOs::Keypad_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${AOs::Keypad_ctor} ......................................................*/
void Keypad_ctor(void) {
    Keypad *me = (Keypad *)AO_Keypad;
    QActive_ctor(&me->super, Q_STATE_CAST(&Keypad_initial));
    QTimeEvt_ctorX(&me->timeEvt, &me->super, TIMEOUT_SIG, 0U);
}
/*$enddef${AOs::Keypad_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*$define${AOs::Keypad} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${AOs::Keypad} ...........................................................*/

/*${AOs::Keypad::SM} .......................................................*/
static QState Keypad_initial(Keypad * const me, void const * const par) {
    /*${AOs::Keypad::SM::initial} */
    QTimeEvt_armX(&me->timeEvt,BSP_TICKS_PER_SEC/2,1U);
    return Q_TRAN(&Keypad_Button);
}

/*${AOs::Keypad::SM::System} ...............................................*/
static QState Keypad_System(Keypad * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

/*${AOs::Keypad::SM::System::Button} .......................................*/
static QState Keypad_Button(Keypad * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${AOs::Keypad::SM::System::Button::TIMEOUT} */
        case TIMEOUT_SIG: {

            for(uint8_t i=0;i<3;i++){
                HAL_GPIO_WritePin(GPIOB,ColArr[i], GPIO_PIN_SET);
                for(uint8_t j=0;j<4;j++){
                    if(HAL_GPIO_ReadPin(GPIOE,RowArr[j]) == GPIO_PIN_SET){
                        if((HAL_GetTick() - prevTick[j][i]) > 100 && (LastButtonStateArr[j][i] == 0)){
                            printf("Pressed key : %c\n",keypad[j][i]);
                            PressedKey = keypad[j][i];
                            LastButtonStateArr[j][i] = 1;
                            static QEvt const buttonPressedEvt = {BUTTON_PRESSED_SIG};
                            QACTIVE_POST(AO_Keypad, &buttonPressedEvt,0U);
                        }
                    }else{
                        prevTick[j][i] = HAL_GetTick();
                        LastButtonStateArr[j][i] = 0;
                    }
                }

                HAL_GPIO_WritePin(GPIOB,ColArr[i], GPIO_PIN_RESET);
            }

            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Keypad::SM::System::Button::BUTTON_PRESSED} */
        case BUTTON_PRESSED_SIG: {
            if(PressedKey == '*'){
                start = 1;
                chr = 0;
            }else if(PressedKey != '*' && PressedKey != '#'){
                if(start == 1){
                    Str[chr == 30 ? chr = 0 : chr++] = PressedKey;
                }
            }else if(PressedKey == '#'){
                if(start == 1 && chr != 0){
                    printf("String is : %s\n",Str);
                }
                start = 0;
                chr  = 0;
            }

            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Keypad_System);
            break;
        }
    }
    return status_;
}
/*$enddef${AOs::Keypad} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
