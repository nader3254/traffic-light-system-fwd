/*
 * gpio.h
 *
 * Created: 10/8/2022 4:52:03 AM
 *  Author: Nader Hany
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>


#define register_t   volatile uint8_t*
#define pin_t        uint8_t
#define PA0         0
#define PA1         1
#define PA2         2
#define PA3         3
#define PA4         4
#define PA5         5
#define PA6         6
#define PA7         7
		
#define PA             (register_t)0x3B     // port a output register
#define DA             (register_t)0x3A     // port a direction register
#define IA             (register_t)0x39     // port a input register



#define PinWrite(port,pin,val)            ( (val == 1) ? (*(port) |= (1<<pin)) : (*(port) &=~(1<<pin)) ) 
#define PinToggle(port,pin)               ( *(port) ^= (1<<pin) )
#define PinRead(port,pin)                 ( (*(port) & (1<<pin)) ? 1 : 0 )

#endif /* GPIO_H_ */