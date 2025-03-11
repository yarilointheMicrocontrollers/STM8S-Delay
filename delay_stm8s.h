/* 
 * delay utilite for STM8 family
 * COSMIC and SDCC
 * Title:    Ports STM8S - Series
 * Author:   Yarilo - David 
 * Software: ST - Visual Develop + Cosmic
 * Telegram: https://t.me/MicrocontrollersSTMAV
 * credits: Terentiev Oleg
 * credits: t.oleg@ymail.com
 */

#ifndef _UTIL_DELAY_H_
#define _UTIL_DELAY_H_ 1

#ifndef F_CPU
#warning F_CPU is not defined!
#endif
/* 
 * Func delayed N cycles, where N = 3 + ( ticks * 3 )
 * so, ticks = ( N - 3 ) / 3, minimum delay is 6 CLK
 * when tick = 1, because 0 equels 65535
 */

/* Caution in@inline void.... */
static @inline void _delay_cycl( unsigned short __ticks){
#if defined(__CSMC__)

#define T_COUNT(x) (( F_CPU * x / 1000000UL )-3)/3)
	// ldw X, __ticks ; insert automaticaly
	_asm("nop\n $N:\n decw X\n jrne $L\n nop\n ", __ticks);
#endif
	}

static @inline void _delay_us(unsigned short __us){
	_delay_cycl( (unsigned short)( T_COUNT(__us));
	}

static @inline void _delay_ms(unsigned short __ms){
	while (__ms--){
	_delay_us(1000);
	}
}
#endif
