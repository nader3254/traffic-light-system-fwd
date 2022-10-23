/*
 * traffic.h
 *
 * Created: 10/8/2022 5:00:41 AM
 *  Author: Nader hany
 */ 


#ifndef TRAFFIC_H_
#define TRAFFIC_H_

#include "time.h"
#include "led.h"



typedef enum
{
	open=0,
	wait=1,
	close=2
	
}traffst_t;

typedef enum
{
	true=1,
	false=0
	
}bool;

typedef struct  
{
	led_t red;
	led_t green;
	led_t yellow;
	
	traffst_t state;
	
	bool NextStateFlag;	
    bool BlinkFlag;
	bool ChangeStateFlag;
	
}TrafficLight_t;

//static uint8_t Total_Traffic_NO=0; //maximum number 2 traffic lights 
static TrafficLight_t* TRAFF1;
static TrafficLight_t* TRAFF2;

void T0_callback0();
void T0_callback1();
void T0_callback2();
void T0_callback3();

void Traffic1_init(TrafficLight_t* traff);
void Traffic2_init(TrafficLight_t* traff);

void Traffic1_start();
void Traffic2_start();

void Traffic1_SetState(traffst_t state);
void Traffic2_SetState(traffst_t state);

void Traffic1_FSM();
void Traffic2_FSM();

#endif /* TRAFFIC_H_ */