#include "msp.h"
#include "ADC14.h"
#include "Clock.h"


uint32_t leftDist, centerDist, rightDist;
int i;
float leftData;
float centerData;
float rightData;

/**
 * main.c
 */
void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	Clock_Init48MHz();
	ADC0_InitSWTriggerCh17_14_16(); // initialize ADC

	while(1){
 	    leftData = 0;
	    centerData = 0;
	    rightData = 0;

	    Clock_Delay1ms(10);
	    for (i = 0; i < 30; i++){
	        ADC_In17_14_16(&leftDist, &centerDist, &rightDist);
	        Clock_Delay1ms(10);
	        leftData += leftDist;
	        rightData+= rightDist;
	        centerData += centerDist;
	    }

	    leftData /= 30.0;
	    rightData /= 30.0;
	    centerData /= 30.0;


	}
}
