/*.$file${../Core/Src::QHSM_Test.h} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: qhsmtst.qm
* File:  ${../Core/Src::QHSM_Test.h}
*
* This code has been generated by QM 5.1.1 <www.state-machine.com/qm/>.
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
/*.$endhead${../Core/Src::QHSM_Test.h} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#ifndef QHSM_TEST_H
#define QHSM_TEST_H


#include "main.h"
#include "stdbool.h"
#include "qep.h"
#include "qpc.h"
#include "bsp.h"


enum QHSM_Test_Signals{
    A_SIG = Q_USER_SIG,
    B_SIG,
    C_SIG,
    D_SIG,
    E_SIG,
    F_SIG,
    G_SIG,
    H_SIG,
    I_SIG,
    TERMINATE_SIG,
    MAX_SIG
};


/*.$declare${HSMs::super_QHsmTst} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
extern QHsm *const super_QHsmTst;
/*.$enddecl${HSMs::super_QHsmTst} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$declare${HSMs::QHsmTst_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${HSMs::QHsmTst_ctor} ...................................................*/
void QHsmTst_ctor(void);
/*.$enddecl${HSMs::QHsmTst_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/




#endif
