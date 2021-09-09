#ifndef GPIO_STRUCT
#define GPIO_STRUCT

#include <stdio.h>
#include <wiringPi.h>

struct Gpio{
	bool runing;
	
	Gpio(){
		runing = false;
	}
	void setup(){
		if( !runing && wiringPiSetupGpio () == -1){
			printf ("ERROR al iniciar wirinpPiSetupGpio.\n");
			runing=false;
		}else{
			runing=true;
		}
	}
}gpio;
#endif
