#ifndef BUZZER_STRUCT
#define BUZZER_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "gpioStruct.h"
#include "pinStruct.h"

struct Buzzer:Pin{
	
	Buzzer(int x):Pin(x){}
	
	void sound(int n, int utime){
		for(int i=0;i<n;i++){
			on();usleep(utime);
			off();usleep(utime);
		}		
	}
};
#endif
