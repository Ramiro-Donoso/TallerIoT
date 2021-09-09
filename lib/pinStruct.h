#ifndef PIN_STRUCT
#define PIN_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "gpioStruct.h"

struct Pin{
	int pin=-1;
	
	Pin(int x){
		pin = x;
		gpio.setup();
		pinMode (pin , OUTPUT );
	}
	void on(){
		if( pin!= -1 ){
			digitalWrite (pin , HIGH );
		}else{
			printf ("ERROR Pin no definido.\n");
			exit(0);
		}
	}
	void off(){
		if( pin!= -1 ){
			digitalWrite (pin , LOW );
		}else{
			printf ("ERROR Pin no definido.\n");
			exit(0);
		}
	}	
};
#endif
