/*
 * keypad.h
 *
 * Created: 1/12/2023 1:11:04 PM
 *  Author: ahmed saad
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "keypad_config.h"

void Keypad_Init();
u8 Keypad_GetPressedKey();

#endif /* KEYPAD_H_ */
