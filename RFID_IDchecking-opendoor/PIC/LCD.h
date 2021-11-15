#ifndef _LCD_
#define _LCD_
#include <16F877A.h>
#device PIC16F877*=16 ADC=10    // Su dung con tro 16bit (cho MCU 14bit)  
                                // Su dung ADC 10bit
#fuses hs, nowdt, noprotect, nolvp, put, brownout
#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=rfid)

#define LCD_ENABLE_PIN PIN_E0
#define LCD_RS_PIN PIN_E1
#define LCD_RW_PIN PIN_E2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
#endif

