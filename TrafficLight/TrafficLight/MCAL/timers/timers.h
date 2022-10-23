/*
 * timers.h
 *
 * Created: 10/8/2022 4:53:58 AM
 *  Author: Nader Hany
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include <stdint.h>
#include <avr/interrupt.h>

/****************modify these if you want to use any call back ****************/

#define USE_CALLBACK0             1
#define USE_CALLBACK1             1
#define USE_CALLBACK2             1
#define USE_CALLBACK3             1
#define USE_CALLBACK4             0
#define USE_CALLBACK5             0




#define EN_IRQ      *((volatile uint8_t*)0x5f) |= 0x80;

#define TOIE0       0
#define OCIE0       1

#define CS00        0
#define CS01        1
#define CS02        2
#define WGM01       3
#define COM00       4
#define COM01       5
#define WGM00       6
#define FOC0        7


#define T0_CONTROLLER       *((volatile uint8_t*)0x53)
#define T0_COUNTER          *((volatile uint8_t*)0x52)
#define T0_OUTPUT_COMPARE   *((volatile uint8_t*)0x5c)
#define T0_INTERRUPT        *((volatile uint8_t*)0x59)

 
//to avoid not executing the uninitialized channels routines 
 static int16_t channle1  = 0;
 static int16_t dchannel1 = 4;
 
 static int16_t channle2  = 0;
 static int16_t dchannel2 = 4;
 
 static int16_t channle3  = 0;
 static int16_t dchannel3 = 4;
  
 static int16_t channle4  = 0;
 static int16_t dchannel4 = 4;
   
 static int16_t channle5  = 0;
 static int16_t dchannel5 = 4;

void Timer0_init();
void Timer0_init_ch1(uint16_t delay_MS );
void Timer0_init_ch2(uint16_t delay_MS );
void Timer0_init_ch3(uint16_t delay_MS );
void Timer0_init_ch4(uint16_t delay_MS );
void Timer0_init_ch5(uint16_t delay_MS );

void Timer0_ch1RST();
void Timer0_ch2RST();
void Timer0_ch3RST();
void Timer0_ch4RST();
void Timer0_ch5RST();


void  T0_callback0();
void  T0_callback1();
void  T0_callback2();
void  T0_callback3();
void  T0_callback4();




#endif /* TIMERS_H_ */