#include "tm4c123gh6pm.h"


#define RCGCGPIO (*((volatile unsigned long*) 0x400FE108 ))
#define PORTEDAT  (*((volatile unsigned long*)0x400243FC))

#define SW1 (*((volatile unsigned long*) 0x40024004 ))
#define LED (*((volatile unsigned long*) 0x40024008 ))
	

#define PORTEDIR (*((volatile unsigned long*)0x40024400))
#define PORTEDEN (*((volatile unsigned long*)0x4002451C))
#define PORTEPUR  (*((volatile unsigned long*)0x40024510))
#define PORTEAFSEL  (*((volatile unsigned long*)0x40024420))
#define PORTECR (*((volatile unsigned long*)0x40024524))
#define PORTEAMSEL (*((volatile unsigned long*)0x40024528))



void delay (int value){
	 
	int time = 0;
	
	while(time<value){
		
		time++;
	}
}
	


int main(){
	RCGCGPIO = 0x10;
	
	GPIOE->DIR = 0x02;
	GPIOE->DEN = 0x03;
	GPIOE->AFSEL = 0x00;
	GPIOE->AMSEL = 0x00;
	GPIOE->PUR = 0x00;


	PORTEDAT = 0x02;
	
	
	while(1)
	{
		PORTEDAT = 0xFF;
		LED = 0x02;
		if(	SW1 ==1){

			delay(197128);
			LED = 0;
			delay(395256);


			
	}
}
}


	
