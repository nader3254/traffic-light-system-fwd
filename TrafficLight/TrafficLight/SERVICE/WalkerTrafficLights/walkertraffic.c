/*
 * walkertraffic.c
 *
 * Created: 10/8/2022 5:03:31 AM
 *  Author: FAYROUZE
 */ 

#include "walkertraffic.h"

void WalkerTraffic_init()
{
	WalkerTrafficLights.TL.red.port=PA;
	WalkerTrafficLights.TL.red.pin=PA3;
	
	WalkerTrafficLights.TL.yellow.port=PA;
	WalkerTrafficLights.TL.yellow.pin=PA4;
	
	WalkerTrafficLights.TL.green.port=PA;
	WalkerTrafficLights.TL.green.pin=PA5;
	
	Traffic1_init(&WalkerTrafficLights.TL);
	
	
}
void WalkerTraffic_start()
{
	Traffic1_start();
	WalkerTraffic_RespondWalkRequest();
	WalkerTraffic_RespondUpdateRequest();

	
	
}
void WalkerTraffic_RespondUpdateRequest()
{
	if (CarTrafficLights.UpdateEvent==true)
	{
		if (CarTrafficLights.TL.state==open)
		{
			Traffic1_SetState(close);
			WalkerInterface_ChangeStatus();
		}
		if (CarTrafficLights.TL.state==close)
		{
			Traffic1_SetState(open);
			
		}
		if (CarTrafficLights.TL.state==wait)
		{
			Traffic1_SetState(wait);
		}
		
		CarTrafficLights.UpdateEvent=false;
	}
	
	
}

void WalkerTraffic_RespondWalkRequest()
{
	if (WalkerTrafficLights.TL.state!=open)
	{
			if (WalkerTrafficLights.WalkRequest==true) //dont forget to disable it
			{
				CarTrafficLights.StopRequest=true;
				Traffic1_SetState(wait);
				WalkerTrafficLights.WalkRequest=false;
			}
			
	}

			    

		
}