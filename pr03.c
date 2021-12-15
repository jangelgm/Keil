#include "LPC17xx.h"                    // Device header
#include "GPIO_LPC17xx.h"               // Keil::Device:GPIO
#include "PIN_LPC17xx.h"                // Keil::Device:PIN

GPIO_ID LED = {1,18};

int main (void)
{	    		
	uint32_t j;
	 
 PIN_Configure (LED.num,LED.port, PIN_FUNC_0, PIN_PINMODE_PULLUP, PIN_PINMODE_NORMAL);
	
 GPIO_SetDir (LED.num,LED.port,GPIO_DIR_OUTPUT);

 GPIO_PinWrite (LED.num,LED.port,0);
	
	//Loop LED Test
	while(1)
	{
		GPIO_PinWrite (LED.num,LED.port,0);
		for(j = 1000000; j > 0; j--);
		GPIO_PinWrite (LED.num,LED.port,1);
		for(j = 1000000; j > 0; j--);
	}
}
