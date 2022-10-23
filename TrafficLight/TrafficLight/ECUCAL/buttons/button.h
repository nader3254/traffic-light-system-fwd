/*
 * button.h
 *
 * Created: 10/8/2022 5:01:34 AM
 *  Author: Nader Hany
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "gpio.h"

typedef enum
{
	pressed,
	released
}btnst;



typedef enum
{
	pull_up=1,
	floating=0
	
}ActiveEdge_t;

typedef struct  
{
	register_t port;
	pin_t pin;
    ActiveEdge_t edge;
}button_t;

void  button_init(button_t btn);
btnst button_read(button_t btn);



#endif /* BUTTON_H_ */