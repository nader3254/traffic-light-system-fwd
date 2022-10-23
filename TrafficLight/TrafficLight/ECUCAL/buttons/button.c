/*
 * button.c
 *
 * Created: 10/8/2022 5:01:17 AM
 *  Author: Nader Hany
 */ 

#include "button.h"

void button_init(button_t btn)
{
	if (btn.port==PA)
	{
		PinWrite(DA,btn.pin,0);
		
		
	}
	
}


btnst button_read(button_t btn)
{

		 if (btn.edge==pull_up)
		 {
			 if (btn.port==PA)
			 {
				 if (PinRead(IA,btn.pin))
				 {
					 return released;
				 }
				 else
				 {
					 return pressed;
				 }
			 }
			 
		 }
		 else
		 {
			 
			 if (btn.port==PA)
			 {
				 if (PinRead(IA,btn.pin))
				 {
					 return pressed;
				 }
				 else
				 {
					 return released;
				 }
			 }
		 }
	
 
}