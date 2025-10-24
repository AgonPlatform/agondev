;****************************************************************************
; *  Copyright (C) 1999-2008 by  Zilog, Inc.
; *  All Rights Reserved
; ****************************************************************************

; Programmable Reload Counter/Timers 
.set TMR0_CTL     , 0x80
.set TMR0_DR_L    , 0x81
.set TMR0_RR_L    , 0x81
.set TMR0_DR_H    , 0x82
.set TMR0_RR_H    , 0x82
.set TMR1_CTL     , 0x83
.set TMR1_DR_L    , 0x84
.set TMR1_RR_L    , 0x84
.set TMR1_DR_H    , 0x85
.set TMR1_RR_H    , 0x85
.set TMR2_CTL     , 0x86
.set TMR2_DR_L    , 0x87
.set TMR2_RR_L    , 0x87
.set TMR2_DR_H    , 0x88
.set TMR2_RR_H    , 0x88
.set TMR3_CTL     , 0x89
.set TMR3_DR_L    , 0x8A
.set TMR3_RR_L    , 0x8A
.set TMR3_DR_H    , 0x8B
.set TMR3_RR_H    , 0x8B
.set TMR4_CTL     , 0x8C
.set TMR4_DR_L    , 0x8D
.set TMR4_RR_L    , 0x8D
.set TMR4_DR_H    , 0x8E
.set TMR4_RR_H    , 0x8E
.set TMR5_CTL     , 0x8F
.set TMR5_DR_L    , 0x90
.set TMR5_RR_L    , 0x90
.set TMR5_DR_H    , 0x91
.set TMR5_RR_H    , 0x91
.set TMR_ISS      , 0x92

; Watch-Dog Timer 
.set WDT_CTL      , 0x93
.set WDT_RR       , 0x94

; General-Purpose Input/Output Ports 
.set PB_DR        , 0x9A
.set PB_DDR       , 0x9B
.set PB_ALT1      , 0x9C
.set PB_ALT2      , 0x9D
.set PC_DR        , 0x9E
.set PC_DDR       , 0x9F
.set PC_ALT1      , 0xA0
.set PC_ALT2      , 0xA1
.set PD_DR        , 0xA2
.set PD_DDR       , 0xA3
.set PD_ALT1      , 0xA4
.set PD_ALT2      , 0xA5

; Chip Select/Wait State Generator 
.set CS0_LBR      , 0xA8
.set CS0_UBR      , 0xA9
.set CS0_CTL      , 0xAA
.set CS1_LBR      , 0xAB
.set CS1_UBR      , 0xAC
.set CS1_CTL      , 0xAD
.set CS2_LBR      , 0xAE
.set CS2_UBR      , 0xAF
.set CS2_CTL      , 0xB0
.set CS3_LBR      , 0xB1
.set CS3_UBR      , 0xB2
.set CS3_CTL      , 0xB3

; On-Chip Random Access Memory Control 
.set RAM_CTL      , 0xB4
.set RAM_ADDR_U   , 0xB5

; Serial Peripheral Interface 
.set SPI_BRG_L    , 0xB8
.set SPI_BRG_H    , 0xB9
.set SPI_CTL      , 0xBA
.set SPI_SR       , 0xBB
.set SPI_TSR      , 0xBC
.set SPI_RBR      , 0xBC

; Infrared Encoder/Decoder 
.set IR_CTL       , 0xBF

; Universal Asynchronous Receiver/Transmitter 0 (UART0) 
.set UART0_RBR    , 0xC0
.set UART0_THR    , 0xC0
.set UART0_BRG_L  , 0xC0
.set UART0_IER    , 0xC1
.set UART0_BRG_H  , 0xC1
.set UART0_IIR    , 0xC2
.set UART0_FCTL   , 0xC2
.set UART0_LCTL   , 0xC3
.set UART0_MCTL   , 0xC4
.set UART0_LSR    , 0xC5
.set UART0_MSR    , 0xC6
.set UART0_SPR    , 0xC7

; Inter-Integrated Circuit Bus Control (I2C) 
.set I2C_SAR      , 0xC8
.set I2C_XSAR     , 0xC9
.set I2C_DR       , 0xCA
.set I2C_CTL      , 0xCB
.set I2C_SR       , 0xCC
.set I2C_CCR      , 0xCC
.set I2C_SRR      , 0xCD

; Universal Asynchronous Receiver/Transmitter 1 (UART1) 
.set UART1_RBR    , 0xD0
.set UART1_THR    , 0xD0
.set UART1_BRG_L  , 0xD0
.set UART1_IER    , 0xD1
.set UART1_BRG_H  , 0xD1
.set UART1_IIR    , 0xD2
.set UART1_FCTL   , 0xD2
.set UART1_LCTL   , 0xD3
.set UART1_MCTL   , 0xD4
.set UART1_LSR    , 0xD5
.set UART1_MSR    , 0xD6
.set UART1_SPR    , 0xD7

; Low-Power Control 
.set CLK_PPD1     , 0xDB
.set CLK_PPD2     , 0xDC

; Real-Time Clock 
.set RTC_SEC      , 0xE0
.set RTC_MIN      , 0xE1
.set RTC_HRS      , 0xE2
.set RTC_DOW      , 0xE3
.set RTC_DOM      , 0xE4
.set RTC_MON      , 0xE5
.set RTC_YR       , 0xE6
.set RTC_CEN      , 0xE7
.set RTC_ASEC     , 0xE8
.set RTC_AMIN     , 0xE9
.set RTC_AHRS     , 0xEA
.set RTC_ADOW     , 0xEB
.set RTC_ACTRL    , 0xEC
.set RTC_CTRL     , 0xED

; Chip Select Bus Mode Control 
.set CS0_BMC      , 0xF0
.set CS1_BMC      , 0xF1
.set CS2_BMC      , 0xF2
.set CS3_BMC      , 0xF3

; On-Chip Flash Memory Control 
.set FLASH_KEY    , 0xF5
.set FLASH_DATA   , 0xF6
.set FLASH_ADDR_U , 0xF7
.set FLASH_CTRL   , 0xF8
.set FLASH_FDIV   , 0xF9
.set FLASH_PROT   , 0xFA
.set FLASH_IRQ    , 0xFB
.set FLASH_PAGE   , 0xFC
.set FLASH_ROW    , 0xFD
.set FLASH_COL    , 0xFE
.set FLASH_PGCTL  , 0xFF


; Unspecified register definitions, retained for compatibility 
.set RAM_CTL0     , RAM_CTL


;**********************************************************************
; Interrupt vector offsets for set_vector                              
;**********************************************************************
.set FLASH_IVECT	, 0x08

.set PRT0_IVECT		, 0x0A
.set PRT1_IVECT		, 0x0C
.set PRT2_IVECT		, 0x0E
.set PRT3_IVECT		, 0x10
.set PRT4_IVECT		, 0x12
.set PRT5_IVECT		, 0x14
.set RTC_IVECT		, 0x16
.set UART0_IVECT	, 0x18
.set UART1_IVECT	, 0x1A
.set I2C_IVECT		, 0x1C
.set SPI_IVECT		, 0x1E

.set PORTB0_IVECT	, 0x30
.set PORTB1_IVECT	, 0x32
.set PORTB2_IVECT	, 0x34
.set PORTB3_IVECT	, 0x36
.set PORTB4_IVECT	, 0x38
.set PORTB5_IVECT	, 0x3A
.set PORTB6_IVECT	, 0x3C
.set PORTB7_IVECT	, 0x3E

.set PORTC0_IVECT	, 0x40
.set PORTC1_IVECT	, 0x42
.set PORTC2_IVECT	, 0x44
.set PORTC3_IVECT	, 0x46
.set PORTC4_IVECT	, 0x48
.set PORTC5_IVECT	, 0x4A
.set PORTC6_IVECT	, 0x4C
.set PORTC7_IVECT	, 0x4E

.set PORTD0_IVECT	, 0x50
.set PORTD1_IVECT	, 0x52
.set PORTD2_IVECT	, 0x54
.set PORTD3_IVECT	, 0x56
.set PORTD4_IVECT	, 0x58
.set PORTD5_IVECT	, 0x5A
.set PORTD6_IVECT	, 0x5C
.set PORTD7_IVECT	, 0x5E