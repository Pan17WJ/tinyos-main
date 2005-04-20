/// $Id: ATm128UART.h,v 1.1.2.2 2005-04-20 18:39:10 mturon Exp $

/**
 * Copyright (c) 2004-2005 Crossbow Technology, Inc.  All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 * 
 * IN NO EVENT SHALL CROSSBOW TECHNOLOGY OR ANY OF ITS LICENSORS BE LIABLE TO 
 * ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL 
 * DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF CROSSBOW OR ITS LICENSOR HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH 
 * DAMAGE. 
 *
 * CROSSBOW TECHNOLOGY AND ITS LICENSORS SPECIFICALLY DISCLAIM ALL WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS 
 * ON AN "AS IS" BASIS, AND NEITHER CROSSBOW NOR ANY LICENSOR HAS ANY 
 * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR 
 * MODIFICATIONS.
 */

/// @author Martin Turon <mturon@xbow.com>

#ifndef _H_ATm128UART_h
#define _H_ATm128UART_h

//====================== UART Bus ==================================

typedef uint8_t ATm128_UDR0_t;  //!< USART0 I/O Data Register
typedef uint8_t ATm128_UDR1_t;  //!< USART1 I/O Data Register

/** UART Status Register */
typedef struct
{
    uint8_t mpcm : 1;  //!< UART Multiprocessor Communication Mode
    uint8_t u2x  : 1;  //!< UART Double Transmission Speed 
    uint8_t upe  : 1;  //!< UART Parity Error
    uint8_t dor  : 1;  //!< UART Data Overrun
    uint8_t fe   : 1;  //!< UART Frame Error
    uint8_t udre : 1;  //!< USART Data Register Empty
    uint8_t txc  : 1;  //!< USART Transfer Complete
    uint8_t rxc  : 1;  //!< USART Receive Complete
} ATm128UARTStatus_t;

typedef ATm128UARTStatus_t ATm128_UCSR0A_t;  //!< UART 0 Status Register
typedef ATm128UARTStatus_t ATm128_UCSR1A_t;  //!< UART 1 Status Register

/** UART Control Register */
typedef struct
{
    uint8_t txb8  : 1;  //!< UART Transmit Data Bit 8
    uint8_t rxb8  : 1;  //!< UART Receive Data Bit 8
    uint8_t ucsz  : 1;  //!< UART Character Size
    uint8_t txen  : 1;  //!< UART Transmitter Enable
    uint8_t rxen  : 1;  //!< UART Receiver Enable
    uint8_t udrie : 1;  //!< USART Data Register Enable
    uint8_t txcie : 1;  //!< UART TX Complete Interrupt Enable
    uint8_t rxcie : 1;  //!< UART RX Complete Interrupt Enable 
} ATm128UARTControl_t;

typedef ATm128UARTControl_t ATm128_UCSR0B_t;  //!< UART 0 Control Register
typedef ATm128UARTControl_t ATm128_UCSR1B_t;  //!< UART 1 Control Register

/** UART Control Register */
typedef struct
{
    uint8_t ucpol : 1;  //!< UART Clock Polarity
    uint8_t ucsz  : 2;  //!< UART Character Size
    uint8_t usbs  : 1;  //!< UART Stop Bit Select
    uint8_t upm   : 2;  //!< UART Parity Mode
    uint8_t umsel : 1;  //!< USART Mode Select
    uint8_t rsvd  : 1;  //!< Reserved
} ATm128UARTMode_t;

typedef ATm128UARTMode_t ATm128_UCSR0C_t;  //!< UART 0 Mode Register
typedef ATm128UARTMode_t ATm128_UCSR1C_t;  //!< UART 1 Mode Register

/**
 * ATmega1128 UART baud register settings:
 *      ATM128_<baudRate>_BAUD_<cpuSpeed>
 */
enum {
    ATM128_19200_BAUD_4MHZ  = 12,
    ATM128_38400_BAUD_4MHZ  = 6,
    ATM128_57600_BAUD_4MHZ  = 3,

    ATM128_19200_BAUD_4MHZ_2X  = 25,
    ATM128_38400_BAUD_4MHZ_2X  = 12,
    ATM128_57600_BAUD_4MHZ_2X  = 8,

    ATM128_19200_BAUD_7MHZ  = 23,
    ATM128_38400_BAUD_7MHZ  = 11,
    ATM128_57600_BAUD_7MHZ  = 7,

    ATM128_19200_BAUD_7MHZ_2X  = 47,
    ATM128_38400_BAUD_7MHZ_2X  = 23,
    ATM128_57600_BAUD_7MHZ_2X  = 15,

    ATM128_19200_BAUD_8MHZ  = 25,
    ATM128_38400_BAUD_8MHZ  = 12,
    ATM128_57600_BAUD_8MHZ  = 8,

    ATM128_19200_BAUD_8MHZ_2X  = 51,
    ATM128_38400_BAUD_8MHZ_2X  = 34,
    ATM128_57600_BAUD_8MHZ_2X  = 11,
}

typedef uint8_t ATm128_UBRR0L_t;  //!< UART 0 Baud Register (Low)
typedef uint8_t ATm128_UBRR0H_t;  //!< UART 0 Baud Register (High)

typedef uint8_t ATm128_UBRR1L_t;  //!< UART 1 Baud Register (Low)
typedef uint8_t ATm128_UBRR1H_t;  //!< UART 1 Baud Register (High)



#endif //_H_ATm128UART_h

