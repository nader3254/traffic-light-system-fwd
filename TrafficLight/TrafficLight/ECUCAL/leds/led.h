/*
 * led.h
 *
 * Created: 10/8/2022 5:01:52 AM
 *  Author: Nader Hany
 */ 


#ifndef LED_H_
#define LED_H_

#include "gpio.h"

typedef enum
{
	led_off = 0,
	led_on  = 1
	
}ledst_t;
typedef struct
{
	 register_t port;
	 pin_t      pin;
	 ledst_t   state;
	
}led_t;

void led_init(led_t ld);
void led_write(led_t ld,ledst_t state);
void led_toggle(led_t ld);



#endif /* LED_H_ */