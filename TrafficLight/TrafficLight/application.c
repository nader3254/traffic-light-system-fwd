/*
 * application.c
 *
 * Created: 10/10/2022 3:07:28 AM
 *  Author: FAYROUZE
 */ 
#include "application.h"


void Application_init()
{

   
   	
   WalkerInterface_init();	
   WalkerTraffic_init();
   CarTraffic_init();
	
}
void Application_start()
{
	while (1)
	{

			WalkerInterface_start();
			WalkerTraffic_start();
		    CarTraffic_start();
	}

}