/*
 * timers.c
 *
 * Created: 10/8/2022 4:53:36 AM
 *  Author: FAYROUZE
 */ 
#include "timers.h"



void Timer0_ch1RST()
{
	channle1=0;
}
void Timer0_ch2RST()
{
	channle2=0;
}
void Timer0_ch3RST()
{
	
	channle3=0;
}
void Timer0_ch4RST()
{
	
	channle4=0;
}
void Timer0_ch5RST()
{
	
	channle5=0;
}

void Timer0_init()
{
	EN_IRQ
	T0_CONTROLLER |= (1<<WGM01);                  // waveform generation -ctc mode
	T0_CONTROLLER |= (1<<CS02) | (1<<CS00);       // prescaler 1024
	T0_OUTPUT_COMPARE = 250;                        // timer compare
	T0_INTERRUPT = (1<<OCIE0);                    // enable interrupt	
}
void Timer0_init_ch1(uint16_t delay_MS )
{

	
    dchannel1= ((delay_MS/100)*2);                        // delay of channle 1
   
}

void Timer0_init_ch2(uint16_t delay_MS )
{

	dchannel2= ((delay_MS/100)*2);                        // delay of channle 1
	
}

void Timer0_init_ch3(uint16_t delay_MS )
{
	
	
	dchannel3= ((delay_MS/100)*2);                       // delay of channle 1
	
}

void Timer0_init_ch4(uint16_t delay_MS )
{

	
	dchannel4= ((delay_MS/100)*2);                       // delay of channle 1
	
}

void Timer0_init_ch5(uint16_t delay_MS )
{

	
	dchannel5= ((delay_MS/100)*2);                        // delay of channle 1
	
}





ISR(TIMER0_COMP_vect)
{
#if USE_CALLBACK0 == 1	
    if (channle1==dchannel1)
    {
		T0_callback0();
		channle1=0;
    }
	else
	{
		channle1++;
		
	}
	
#endif	
#if USE_CALLBACK1 == 1
      if (channle2==dchannel2)
      {
	     T0_callback1();
		 channle2=0;
      }
	  else
	  {
		  channle2++;
	  }
   
#endif
#if USE_CALLBACK2 == 1
          if (channle3==dchannel3)
          {
	          T0_callback2();
	          channle3=0;
          }
          else
          {
	          channle3++;
          }
#endif
#if USE_CALLBACK3 == 1
          if (channle4==dchannel4)
          {
	          T0_callback3();
	          channle4=0;
          }
          else
          {
	          channle4++;
          }
#endif
#if USE_CALLBACK4 == 1
          if (channle5==dchannel5)
          {
	          T0_callback4();
	          channle5=0;
          }
          else
          {
	          channle5++;
          }
#endif
	
}