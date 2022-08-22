/*============================================================================
*
*                    Q u a n t u m  L e a P s
*                    ------------------------
*                    Modern Embedded Software
*
* Copyright (C) 2005 Quantum Leaps, LLC. All rights reserved.
*
* SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
*
* This software is dual-licensed under the terms of open-source GPL 3.0
* (or any later version), or alternatively, under the terms of one of the
* closed-source Quantum Leaps commercial licenses.
*
* The terms of the open source GPL 3.0 license can be found at:
* <www.gnu.org/licenses/gpl-3.0.txt>
*
* The terms of the closed-source Quantum Leaps commercial licenses
* can be found at:
* <www.state-machine.com/licensing>
*
* NOTE: Please do NOT plagiarize this software to sidestep the license
* obligations. This is both unfair and illegal.
*
* Contact information:
* <www.state-machine.com>
* <info@state-machine.com>
============================================================================*/
/**
* @date Last updated on: 2021-12-23
* @version Last updated for: @ref qpc_7_0_0
*
* @file
* @brief Internal (package scope) QS/C interface.
*/
#ifndef QS_PKG_H
#define QS_PKG_H

/*==========================================================================*/

/*! QS received record types (RX channel)
* @details
* This enumeration specifies the record types for the QS receive channel
*/
enum QSpyRxRecords {
    QS_RX_INFO,           /*!< query Target info (ver, config, tstamp) */
    QS_RX_COMMAND,        /*!< execute a user-defined command in the Target */
    QS_RX_RESET,          /*!< reset the Target */
    QS_RX_TICK,           /*!< call QF_TICK_X() in the Target */
    QS_RX_PEEK,           /*!< peek Target memory */
    QS_RX_POKE,           /*!< poke Target memory */
    QS_RX_FILL,           /*!< fill Target memory */
    QS_RX_TEST_SETUP,     /*!< test setup */
    QS_RX_TEST_TEARDOWN,  /*!< test teardown */
    QS_RX_TEST_PROBE,     /*!< set a Test-Probe in the Target */
    QS_RX_GLB_FILTER,     /*!< set global filters in the Target */
    QS_RX_LOC_FILTER,     /*!< set local  filters in the Target */
    QS_RX_AO_FILTER,      /*!< set local AO filter in the Target */
    QS_RX_CURR_OBJ,       /*!< set the "current-object" in the Target */
    QS_RX_TEST_CONTINUE,  /*!< continue a test after QS_TEST_PAUSE() */
    QS_RX_QUERY_CURR,     /*!< query the "current object" in the Target */
    QS_RX_EVENT           /*!< inject an event to the Target */
};

/*==========================================================================*/
/*! Frame character of the QS output protocol */
#define QS_FRAME    (0x7EU)

/*! Escape character of the QS output protocol */
#define QS_ESC      (0x7DU)

/*! The expected checksum value over an uncorrupted QS record */
#define QS_GOOD_CHKSUM (0xFFU)

/*! Escape modifier of the QS output protocol */
/**
* @details
* The escaped byte is XOR-ed with the escape modifier before it is inserted
* into the QS buffer.
*/
#define QS_ESC_XOR  (0x20U)

/*==========================================================================*/
/*! send the predefined target info trace record
 * (object sizes, build time-stamp, QP version) */
void QS_target_info_pre_(uint8_t isReset);

/*==========================================================================*/
/*! Private QS-RX attributes to keep track of the current objects and
* the lock-free RX buffer
*/
typedef struct {
    void     *currObj[MAX_OBJ]; /*!< current objects */
    uint8_t  *buf;        /*!< pointer to the start of the ring buffer */
    QSCtr     end;        /*!< offset of the end of the ring buffer */
    QSCtr volatile head;  /*!< offset to where next byte will be inserted */
    QSCtr volatile tail;  /*!< offset of where next byte will be extracted */
#ifdef Q_UTEST
    QPSet     readySet;   /*!< QUTEST ready-set of active objects */
    bool      inTestLoop; /*!< QUTEST event loop is running */
#endif
} QSrxPrivAttr;

extern QSrxPrivAttr QS_rxPriv_; /* QS-RX private attributes */

/*==========================================================================*/
/*! Internal QS macro to begin a predefined QS record with
* entering critical section. */
/**
* @note This macro is intended to use only inside QP components and NOT
* at the application level.
* @sa QS_BEGIN_ID()
*/
#define QS_BEGIN_PRE_(rec_, qs_id_)                     \
    if (QS_GLB_CHECK_(rec_) && QS_LOC_CHECK_(qs_id_)) { \
        QS_CRIT_E_();                                   \
        QS_beginRec_((uint_fast8_t)(rec_));

/*!  Internal QS macro to end a predefined QS record with
* exiting critical section. */
/**
* @note This macro is intended to use only inside QP components and NOT
* at the application level.
* @sa QS_END()
*/
#define QS_END_PRE_() \
        QS_endRec_(); \
        QS_CRIT_X_(); \
    }

/*! Internal macro to begin a predefined QS record without
* entering critical section. */
/**
* @note This macro is intended to use only inside QP components and NOT
* at the application level.
* @sa QS_BEGIN_NOCRIT()
*/
#define QS_BEGIN_NOCRIT_PRE_(rec_, qs_id_)              \
    if (QS_GLB_CHECK_(rec_) && QS_LOC_CHECK_(qs_id_)) { \
        QS_beginRec_((uint_fast8_t)(rec_));

/*! Internal QS macro to end a predefined QS record without
* exiting critical section. */
/**
* @note This macro is intended to use only inside QP components and NOT
* at the application level. @sa #QS_END_NOCRIT
*/
#define QS_END_NOCRIT_PRE_()    QS_endRec_(); }

/*! Internal QS macro to output a predefined uint8_t data element */
#define QS_U8_PRE_(data_)       (QS_u8_raw_((uint8_t)(data_)))

/*! Internal QS macro to output 2 predefined uint8_t data elements */
#define QS_2U8_PRE_(data1_, data2_) \
    (QS_2u8_raw_((uint8_t)(data1_), (uint8_t)(data2_)))

/*! Internal QS macro to output an predefined uint16_t data element */
#define QS_U16_PRE_(data_)      (QS_u16_raw_((uint16_t)(data_)))

/*! Internal QS macro to output a predefined uint32_t data element */
#define QS_U32_PRE_(data_)      (QS_u32_raw_((uint32_t)(data_)))

/*! Internal QS macro to output a predefined zero-terminated string element */
#define QS_STR_PRE_(msg_)       (QS_str_raw_((msg_)))


#if (!defined Q_SIGNAL_SIZE || (Q_SIGNAL_SIZE == 1U))
    /*! Internal macro to output an unformatted event signal data element */
    /**
    * @note the size of the pointer depends on the macro #Q_SIGNAL_SIZE.
    */
    #define QS_SIG_PRE_(sig_)   (QS_u8_raw_((uint8_t)sig_))
#elif (Q_SIGNAL_SIZE == 2U)
    #define QS_SIG_PRE_(sig_)   (QS_u16_raw_((uint16_t)sig_))
#elif (Q_SIGNAL_SIZE == 4U)
    #define QS_SIG_PRE_(sig_)   (QS_u32_raw_((uint32_t)sig_))
#endif

#define QS_OBJ_PRE_(obj_)       (QS_obj_raw_(obj_))

#if (!defined QS_FUN_PTR_SIZE || (QS_FUN_PTR_SIZE == 1U))
    #define QS_FUN_PRE_(fun_)   (QS_u8_raw_((uint8_t)(fun_)))
#elif (QS_FUN_PTR_SIZE == 2U)
    #define QS_FUN_PRE_(fun_)   (QS_u16_raw_((uint16_t)(fun_)))
#elif (QS_FUN_PTR_SIZE == 4U)
    #define QS_FUN_PRE_(fun_)   (QS_u32_raw_((uint32_t)(fun_)))
#elif (QS_FUN_PTR_SIZE == 8U)
    #define QS_FUN_PRE_(fun_)   (QS_u64_raw_((uint64_t)(fun_)))
#else
    /*! Internal macro to output an unformatted function pointer */
    /** @note the size of the pointer depends on the macro #QS_FUN_PTR_SIZE.
    * If the size is not defined the size of pointer is assumed 4-bytes.
    */
    #define QS_FUN_PRE_(fun_)   (QS_u32_raw_((uint32_t)(fun_)))
#endif

/*==========================================================================*/
#if (!defined QF_EQUEUE_CTR_SIZE || (QF_EQUEUE_CTR_SIZE == 1U))

    /*! Internal QS macro to output an unformatted event queue counter
    * data element. */
    /**
    * @note the counter size depends on the macro #QF_EQUEUE_CTR_SIZE.
    */
    #define QS_EQC_PRE_(ctr_)       QS_u8_raw_((uint8_t)(ctr_))
#elif (QF_EQUEUE_CTR_SIZE == 2U)
    #define QS_EQC_PRE_(ctr_)       QS_u16_raw_((uint16_t)(ctr_))
#elif (QF_EQUEUE_CTR_SIZE == 4U)
    #define QS_EQC_PRE_(ctr_)       QS_u32_raw_((uint32_t)(ctr_))
#endif


#if (!defined QF_EVENT_SIZ_SIZE || (QF_EVENT_SIZ_SIZE == 1U))

    /*! Internal QS macro to output an unformatted event size
    * data element. */
    /**
    * @note the event size depends on the macro #QF_EVENT_SIZ_SIZE.
    */
    #define QS_EVS_PRE_(size_)      QS_u8_raw_((uint8_t)(size_))
#elif (QF_EVENT_SIZ_SIZE == 2U)
    #define QS_EVS_PRE_(size_)      QS_u16_raw_((uint16_t)(size_))
#elif (QF_EVENT_SIZ_SIZE == 4U)
    #define QS_EVS_PRE_(size_)      QS_u32_raw_((uint32_t)(size_))
#endif


#if (!defined QF_MPOOL_SIZ_SIZE || (QF_MPOOL_SIZ_SIZE == 1U))

    /*! Internal QS macro to output an unformatted memory pool
    * block-size data element */
    /**
    * @note the block-size depends on the macro #QF_MPOOL_SIZ_SIZE.
    */
    #define QS_MPS_PRE_(size_)      QS_u8_raw_((uint8_t)(size_))
#elif (QF_MPOOL_SIZ_SIZE == 2U)
    #define QS_MPS_PRE_(size_)      QS_u16_raw_((uint16_t)(size_))
#elif (QF_MPOOL_SIZ_SIZE == 4U)
    #define QS_MPS_PRE_(size_)      QS_u32_raw_((uint32_t)(size_))
#endif

#if (!defined QF_MPOOL_CTR_SIZE || (QF_MPOOL_CTR_SIZE == 1U))

    /*! Internal QS macro to output an unformatted memory pool
    * block-counter data element. */
    /**
    * @note the counter size depends on the macro #QF_MPOOL_CTR_SIZE.
    */
    #define QS_MPC_PRE_(ctr_)       QS_u8_raw_((uint8_t)(ctr_))
#elif (QF_MPOOL_CTR_SIZE == 2U)
    #define QS_MPC_PRE_(ctr_)       QS_u16_raw_((uint16_t)(ctr_))
#elif (QF_MPOOL_CTR_SIZE == 4U)
    #define QS_MPC_PRE_(ctr_)       QS_u32_raw_((uint16_t)(ctr_))
#endif


#if (!defined QF_TIMEEVT_CTR_SIZE || (QF_TIMEEVT_CTR_SIZE == 1U))

    /*! Internal QS macro to output an unformatted time event
    * tick-counter data element */
    /**
    * @note the counter size depends on the macro #QF_TIMEEVT_CTR_SIZE.
    */
    #define QS_TEC_PRE_(ctr_)       QS_u8_raw_((uint8_t)(ctr_))
#elif (QF_TIMEEVT_CTR_SIZE == 2U)
    #define QS_TEC_PRE_(ctr_)       QS_u16_raw_((uint16_t)(ctr_))
#elif (QF_TIMEEVT_CTR_SIZE == 4U)
    #define QS_TEC_PRE_(ctr_)       QS_u32_raw_((uint32_t)(ctr_))
#endif

/*==========================================================================*/
/*! Internal QS macro to insert an un-escaped byte into the QS buffer */
#define QS_INSERT_BYTE_(b_) \
    buf[head] = (b_);       \
    ++head;                 \
    if (head == end) {      \
        head = 0U;          \
    }

/*! Internal QS macro to insert an escaped byte into the QS buffer */
#define QS_INSERT_ESC_BYTE_(b_)                      \
    chksum = (uint8_t)(chksum + (b_));               \
    if (((b_) != QS_FRAME) && ((b_) != QS_ESC)) {    \
        QS_INSERT_BYTE_(b_)                          \
    }                                                \
    else {                                           \
        QS_INSERT_BYTE_(QS_ESC)                      \
        QS_INSERT_BYTE_((uint8_t)((b_) ^ QS_ESC_XOR))\
        ++QS_priv_.used;                             \
    }

#endif  /* QS_PKG_H */
