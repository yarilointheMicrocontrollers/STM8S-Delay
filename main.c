/********************************************
* Title:   	Encoder STM8S - Series
* Author:   Yarilo - David Ivan
* Software: ST-Visual Develop + Cosmic
* E-mail:   gothicdreams.crissis@gmail.com
********************************************/

#define _SFR_(mem_addr) (*(volatile unsigned char*)(0x5000+(mem_addr)))

#define ODRE	_SFR_(0x14)		//Define ODRx
#define DDRE	_SFR_(0x16)		//Define DDRx
#define CR1E	_SFR_(0x17)		//Define CR1x

#define ODRC	_SFR_(0x0A)		//Define ODRx
#define DDRC	_SFR_(0x0C)		//Define DDRx
#define CR1C	_SFR_(0x0D)		//Define CR1x

void delay_ms(unsigned int x);

unsigned char ind;
unsigned const int Array[]= {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x100};


main(){
	
	DDRC=0xFE;			// 0b1111 0000 Salida
	CR1C=0xFE;			// Push Pull
	
	DDRE=(1<<5);
	CR1E=(1<<5);
	
	while(1){
	
		ODRE=Array[ind]<<4; 
		ODRC=Array[ind]>>1;
		delay_ms(10);
		if(ind>7)ind=0;
		ind++;
		}
	}

void delay_ms(unsigned int x){					// Funcion de retardo 
	unsigned int i=0;
	for(;x>0;x--)
		for(i=0;i<1142;i++);
	}