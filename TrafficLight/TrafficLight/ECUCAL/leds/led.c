/*
 * led.c
 *
 * Created: 10/8/2022 5:02:02 AM
 *  Author: Nader Hany
 */ 
#include "led.h"

void led_init(led_t ld)
{
      if (ld.port==PA)
      {
		 PinWrite(DA,ld.pin,1);
		 ld.state=led_off;
	  }
	  

}
void led_write(led_t ld,ledst_t state)
{
	
	PinWrite(ld.port,ld.pin,state);
	ld.state=state;
}
void led_toggle(led_t ld)
{
	
	PinToggle(ld.port,ld.pin);
	if (ld.state==led_on)
	{
		ld.state=led_off;
	}
	else
	{
		
		ld.state=led_on;
			
	}
}