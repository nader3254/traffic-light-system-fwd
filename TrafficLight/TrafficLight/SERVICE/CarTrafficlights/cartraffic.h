/*
 * cartraffic.h
 *
 * Created: 10/8/2022 5:02:51 AM
 *  Author: Nader Hany
 */ 


#ifndef CARTRAFFIC_H_
#define CARTRAFFIC_H_

#include "traffic.h"

typedef struct
{
	TrafficLight_t TL;
	traffst_t PrevState;
	bool StopRequest;
	bool StopEvent;
	bool UpdateEvent;
	
}CarTraffic_t;


CarTraffic_t CarTrafficLights;

void CarTraffic_init();
void CarTraffic_start();
void CarTrafficUpdateStatus();
void CarTrafficStopRequest();





#endif /* CARTRAFFIC_H_ */