#ifndef __STM32L476R_NUCLEO_LCD_H
#define __STM32L476R_NUCLEO_LCD_H

#include "stm32l476xx.h"



void delay_ms(unsigned int ms);
void LCD_WriteCom(unsigned char com);
void LCD_WriteData(unsigned char dat);
void LCD_DisplayChar(int loc, unsigned char val);
void LCD_Init(void);
void LCD_Clear(void);
void Pulse(void);

//TA defined Functions
//void LCD_DisplayString(unsigned int line, unsigned char *ptr);
//uint32_t getPin(GPIO_TypeDef * port, uint32_t pin);
//void setPin(GPIO_TypeDef * port, uint32_t pin, uint32_t value);

#endif
