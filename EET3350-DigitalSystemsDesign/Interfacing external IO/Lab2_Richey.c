#include "tm4c123gh6pm.h"

#define PORTFDAT  (*((volatile unsigned long*)0x400253FC))
#define RCGCGPIO (*((volatile unsigned long*) 0x400FE108 ))
#define PORTFDIR (*((volatile unsigned long*)0x40025400))
#define PORTFDEN (*((volatile unsigned long*)0x4002551C))
#define PORTFPUR  (*((volatile unsigned long*)0x40025510))
#define PORTFAFSEL  (*((volatile unsigned long*)0x40025420))
#define PORTFCR (*((volatile unsigned long*)0x40025524))
#define PORTFAMSEL (*((volatile unsigned long*)0x40025528))
#define SW1 (*((volatile unsigned long*) 0x40025040 ))
#define LED (*((volatile unsigned long*) 0x40025010))	
#define LOCK	(*((volatile unsigned long*) 0x40025520))
#define PORTFPCTL (*((volatile unsigned long*) 0x4002552C))
	

void delay (){
	 
	int time = 0;
	
	while(time<1643000){
		
		time++;
	}
	if(time==1643000){
		
		time=0;
		
	}
}
int main(){
	RCGCGPIO= 0x21;
	LOCK = 0x4C4F434B;
	PORTFPCTL = 0x00000000;
	PORTFCR=0x1F;
	PORTFDIR= 0x0C;
	PORTFDEN=0x1F; 
	PORTFPUR=0x10;
	PORTFAFSEL=0x00;
	PORTFAMSEL=0x00;
	GPIOA->DIR = 0x04;
	GPIOA->DEN = 0x04;
	//LED= 0x04;
	GPIOF->DATA = 0x04;
	SW1=0x10;
	PORTFDAT = 0x04;
	GPIOA->DATA = 0x00;
	
	
	
	while(1)
	{
		GPIOF->DATA = 0x04;
		
		if(	SW1==0){
			//LED=0x04;
			GPIOF->DATA = 0x04;
			GPIOA->DATA = 0x04;
			delay();
			GPIOF->DATA &= ~0x04;
			GPIOF->DATA |= 0x08;
			GPIOA->DATA =! 0x04;
			//LED=0x0F;
			delay();
			
	}
		GPIOF->DATA &= ~0x08;
		GPIOA->DATA &= ~0x04;
}
}


	
