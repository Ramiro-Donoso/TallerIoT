#ifndef LEDRGB_STRUCT
#define LEDRGB_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "ledStruct.h"

struct LedRgb{
	Led* ledR;
	Led* ledG;
	Led* ledB;
	
	LedRgb(int x, int y, int z){
		ledR = new Led(x);
		ledG = new Led(y);
		ledB = new Led(z);
	}
	void color(int x, int y, int z){
		if(x==1)
			ledR->off();
		if(x==0)
			ledR->on();
		if(y==1)
			ledG->off();
		if(y==0)
			ledG->on();
		if(z==1)
			ledB->off();
		if(z==0)
			ledB->on();
	}	
};
#endif
