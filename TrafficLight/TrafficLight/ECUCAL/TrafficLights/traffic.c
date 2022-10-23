/*
 * traffic.c
 *
 * Created: 10/8/2022 5:01:02 AM
 *  Author: FAYROUZE
 */ 
#include "traffic.h"
void T0_callback0()
{
	if (TRAFF1->BlinkFlag==true)
	{
		led_toggle(TRAFF1->yellow);
	}
	
	
}
void T0_callback1()
{
	TRAFF1->NextStateFlag=true;
	
	if (TRAFF1->state==close)
	{
		TRAFF1->state=open;
	}
	else
	{
		TRAFF1->state++;
	}
	
}
void T0_callback2()
{
	if (TRAFF2->BlinkFlag==true)
	{
		led_toggle(TRAFF2->yellow);
	}
	
	
}
void T0_callback3()
{
	TRAFF2->NextStateFlag=true;
	
	if (TRAFF2->state==close)
	{
		TRAFF2->state=open;
	}
	else
	{
		TRAFF2->state++;
	}
	
}


void Traffic1_init(TrafficLight_t* traff)
{
	TRAFF1 = traff;
	led_init(traff->red);
	led_init(traff->yellow);
	led_init(traff->green);
	
	Timer0_init();
	
	Timer0_init_ch1(500);     // to drive waiting state
	Timer0_init_ch2(5000);    // to drive changing states every 5 seconds
	
	TRAFF1->state=close;
	TRAFF1->NextStateFlag=true;
}

void Traffic2_init(TrafficLight_t* traff)
{
		TRAFF2 = traff;
		led_init(traff->red);
		led_init(traff->yellow);
		led_init(traff->green);
	
	Timer0_init();
	
	Timer0_init_ch3(500);     // to drive waiting state
	Timer0_init_ch4(5000);    // to drive changing states every 5 seconds

	TRAFF2->state=close;
	TRAFF2->NextStateFlag=true;
}

void Traffic1_FSM()
{
	if (TRAFF1->state==close)
	{
		TRAFF1->BlinkFlag     = false;
		TRAFF1->NextStateFlag = false;
		
		led_write(TRAFF1->red   ,led_on);
		led_write(TRAFF1->yellow,led_off);
		led_write(TRAFF1->green ,led_off);
		
	}
	
	if (TRAFF1->state==open)
	{
		TRAFF1->BlinkFlag     = false;
		TRAFF1->NextStateFlag = false;
		
		led_write(TRAFF1->red   ,led_off);
		led_write(TRAFF1->yellow,led_off);
		led_write(TRAFF1->green ,led_on);
	}
	
	if (TRAFF1->state==wait)
	{
		TRAFF1->BlinkFlag     = true;
		TRAFF1->NextStateFlag = false;
		
		led_write(TRAFF1->red   ,led_off);
		led_write(TRAFF1->green ,led_off);
		
	}
	
}
void Traffic2_FSM()
{
	
	if (TRAFF2->state==close)
	{
		TRAFF2->BlinkFlag     = false;
		TRAFF2->NextStateFlag = false;
		
		led_write(TRAFF2->red   ,led_on);
		led_write(TRAFF2->yellow,led_off);
		led_write(TRAFF2->green ,led_off);
		
	}
	
	if (TRAFF2->state==open)
	{
		TRAFF2->BlinkFlag     = false;
		TRAFF2->NextStateFlag = false;
		
		led_write(TRAFF2->red   ,led_off);
		led_write(TRAFF2->yellow,led_off);
		led_write(TRAFF2->green ,led_on);
	}
	
	if (TRAFF2->state==wait)
	{
		TRAFF2->BlinkFlag     = true;
		TRAFF2->NextStateFlag = false;
		
		led_write(TRAFF2->red   ,led_off);
		led_write(TRAFF2->green ,led_off);
	}
	
}

void Traffic1_start()
{
	if (TRAFF1->NextStateFlag==true)
	{
        Traffic1_FSM();
		
	}
	if (TRAFF1->ChangeStateFlag==true)
	{
		Timer0_ch2RST();
		Traffic1_FSM();
		TRAFF1->ChangeStateFlag=false;
		
	}
	
}

void Traffic2_start()
{
	if (TRAFF2->NextStateFlag==true)
	{
		Traffic2_FSM();
		
	}
	if (TRAFF2->ChangeStateFlag==true)
	{
		Timer0_ch4RST();
		Traffic2_FSM();
		TRAFF2->ChangeStateFlag=false;
		
	}
	
}

void Traffic1_SetState(traffst_t state)
{
	TRAFF1->ChangeStateFlag = true;
	TRAFF1->state           = state;
}

void Traffic2_SetState(traffst_t state)
{
	TRAFF2->ChangeStateFlag = true;
	TRAFF2->state           = state;
}
