/*
 * walkerinterface.c
 *
 * Created: 10/8/2022 5:03:55 AM
 *  Author: FAYROUZE
 */ 

#include "walkerinterface.h"

void WalkerInterface_init()
{
	walker_btn.port=PA;
	walker_btn.pin= PA7;
	walker_btn.edge=floating;
	button_init(walker_btn);
	locker=unlocked;
	
	   PowerIndicator.port = PA;
	   PowerIndicator.pin  = PA6;
	   led_init(PowerIndicator);
	   led_write(PowerIndicator,led_on);
	
}
void WalkerInterface_start()
{
	
	
  if(locker==unlocked)
  {
	  
	if(button_read(walker_btn)==pressed)
	{
		
		 led_write(PowerIndicator,led_on);
		 WalkerInterface_sendWalkRequest();
		 locker=locked;
	}
	else
	{
		 led_write(PowerIndicator,led_off);
	}
  }
}
void WalkerInterface_sendWalkRequest()
{
	WalkerTrafficLights.WalkRequest = true;
	
}
void WalkerInterface_ChangeStatus()
{
	locker=unlocked;
}