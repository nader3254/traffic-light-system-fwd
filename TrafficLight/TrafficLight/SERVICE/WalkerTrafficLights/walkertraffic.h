/*
 * walkertraffic.h
 *
 * Created: 10/8/2022 5:03:13 AM
 *  Author: Nader Hany
 */ 


#ifndef WALKERTRAFFIC_H_
#define WALKERTRAFFIC_H_

#include "traffic.h"
#include "cartraffic.h"
typedef struct
{
	TrafficLight_t TL;
	bool WalkRequest;
	bool WalkRequestExecuted;
	
}WalkerTraffic_t;

WalkerTraffic_t WalkerTrafficLights;

void WalkerTraffic_init();
void WalkerTraffic_start();
void WalkerTraffic_RespondUpdateRequest();
void WalkerTraffic_RespondWalkRequest();


#endif /* WALKERTRAFFIC_H_ */



