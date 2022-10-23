/*
 * cartraffic.c
 *
 * Created: 10/8/2022 5:02:38 AM
 *  Author: FAYROUZE
 */ 
#include "cartraffic.h"

void CarTraffic_init()
{

	
	CarTrafficLights.TL.red.port=PA;
	CarTrafficLights.TL.red.pin=PA0;
	
	CarTrafficLights.TL.yellow.port=PA;
	CarTrafficLights.TL.yellow.pin=PA1;
	
	CarTrafficLights.TL.green.port=PA;
	CarTrafficLights.TL.green.pin=PA2;
	
	Traffic2_init(&CarTrafficLights.TL);
	CarTrafficLights.PrevState=CarTrafficLights.TL.state;
	
}
void CarTraffic_start()
{
	Traffic2_start();
	CarTrafficUpdateStatus();
    CarTrafficStopRequest();
	
	
}
void CarTrafficUpdateStatus()
{
	if (CarTrafficLights.TL.state != CarTrafficLights.PrevState)
	{
		CarTrafficLights.UpdateEvent=true;
		CarTrafficLights.PrevState=CarTrafficLights.TL.state;
	}
	
}
void CarTrafficStopRequest()
{
	if (CarTrafficLights.StopRequest==true)
	{
		Traffic2_SetState(wait);
		CarTrafficLights.StopRequest=false;
	
	
	}
		

	
	
}
