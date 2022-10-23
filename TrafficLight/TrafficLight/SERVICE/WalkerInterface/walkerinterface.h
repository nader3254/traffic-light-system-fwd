/*
 * walkerinterface.h
 *
 * Created: 10/8/2022 5:04:13 AM
 *  Author: Nader Hany
 */ 


#ifndef WALKERINTERFACE_H_
#define WALKERINTERFACE_H_


#include "walkertraffic.h"
#include "button.h"

button_t walker_btn;
typedef enum
{
	locked,
	unlocked
	
}lock_t;

led_t PowerIndicator;
lock_t locker;

void WalkerInterface_init();
void WalkerInterface_start();
void WalkerInterface_sendWalkRequest();
void WalkerInterface_ChangeStatus();

#endif /* WALKERINTERFACE_H_ */