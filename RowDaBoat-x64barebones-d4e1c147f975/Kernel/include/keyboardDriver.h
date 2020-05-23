#ifndef _KEYBOARD_DRIVER_H_
#define _KEYBOARD_DRIVER_H_
#include <stdint.h>

void poolingKeyboard();
void keyboard_handler();
uint8_t hasKey(void);
uint8_t getKey(void);


#endif