/*
 * main.c
 *
 * Created: 10/8/2022 4:49:21 AM
 * Author : Nader Hany
 */ 

//#include "gpio.h"
/*#include <avr/delay.h>
#include "led.h"
#include "button.h"
#include "traffic.h"
*/

/* timer0 overflow interrupt */


#include "application.h"


int main( void )
{
   Application_init();
   Application_start();
	
	/*button_t walker_btn;
	walker_btn.port=PA;
	walker_btn.pin= PA7;
	walker_btn.edge=floating;
	button_init(walker_btn);
	
	   PowerIndicator.port = PA;
	   PowerIndicator.pin  = PA6;
	   led_init(PowerIndicator);
	   led_write(PowerIndicator,led_on);
	   
	   
	   while(1)
	   {
		   
		   	if(button_read(walker_btn)==pressed)
		   	{
			   	led_write(PowerIndicator,led_on);
		   	}
		   	else
		   	{
			   	
			   	led_write(PowerIndicator,led_off);
		   	}
	   }
*/
}


/*
	button_t walker_btn;
	walker_btn.port=PA;
	walker_btn.pin= PA7;
	walker_btn.edge=floating;
	button_init(walker_btn);
	
	TrafficLight_t t1;
	t1.red.port=PA;
	t1.red.pin=PA0;
	
	t1.yellow.port=PA;
	t1.yellow.pin=PA1;
	
	t1.green.port=PA;
	t1.green.pin=PA2;
	
	Traffic2_init(&t1);
	
	while(1)
	{
		Traffic2_start();
		if (button_read(walker_btn)==pressed)
		{
			Traffic2_SetState(wait);
		}
		
	}
*/
//#include <avr/io.h>
/*int main(void)
{
    
	


	led_t PowerIndicator;
	PowerIndicator.port=PA;
	PowerIndicator.pin=PA6;
	led_init(PowerIndicator);
	
	button_t walker_btn;
	walker_btn.port=PA;
	walker_btn.pin= PA7;
	walker_btn.edge=floating;
	button_init(walker_btn);
	//PinWrite(DA,PA7,0);
	
    while (1) 
    {


			led_toggle(PowerIndicator);
			//led_write(PowerIndicator,led_on);
		
		
		
    }
}
*/

