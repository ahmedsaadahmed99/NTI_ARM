/*
 * keypad_config.h
 *
 * Created: 1/12/2023 1:29:34 PM
 *  Author: ahmed saad
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO_interface.h"

#define  COLUMN_PORT  PORTB
#define  ROW_PORT     PORTA
#define  C1_PIN       PIN9
#define  C2_PIN       PIN10
#define  C3_PIN       PIN11
#define  C4_PIN       PIN12
#define  R1_PIN       PIN0
#define  R2_PIN       PIN1
#define  R3_PIN       PIN2
#define  R4_PIN       PIN3
#define  N_COL        4
#define  N_ROW        4
#define  KEYPAD_HIGH  1
#define  KEYPAD_LOW   0

#endif
