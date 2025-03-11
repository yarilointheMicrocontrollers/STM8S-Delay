/* 
 * Author:	 Yarilo - David Ivan
 * Software: ST-Visual Develop + Cosmic
 * Project:	 Pantalla LCD con STM8S207K6
 * Telegram: https://t.me/MicrocontrollersSTMAV
 * Tiktok:	 https://www.tiktok.com/@the_w_rkncacnter_avr
 * IG:			 https://www.instagram.com/yarilo_microcontrollers
 */

#include "stm8s207k6.h"
#define F_CPU 2000000
#include "delay.h"

main(){
	
	/* 
	 * DDRC0 | DDRC2 | DDRC3
	 * CR1C0 | CR1C2 | DDRC3
	 */ 
	 
	GPIOD->DDR|=0x0B;		  // Set As Mode 
	GPIOD->CR1|=0x0B;			// Set As push pull  
	while(1){
		
		//ODRD|=(1<<0);
		GPIOD->ODR|=0x0B;	// Set GPIO 0x0B
		_delay_us(150);
		//ODRD&=~(1<<0);
		GPIOD->ODR=0x00;	// set Output 0x00
		_delay_us(150);
		}
	
}