#ifndef LED_STRUCT
#define LED_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "gpioStruct.h"
#include "pinStruct.h"

struct Led:Pin{
	bool booleanBlink = false;
	int speedBlink=0;
	
	Led(int x):Pin(x){}
	void blink(int nTimesXseg){
		if( pin!= -1 ){
			if(!isBlinking() && nTimesXseg > 0){
				booleanBlink=true;
				speedBlink=nTimesXseg;
				pthread_t h;
				pthread_create(&h, NULL, blink_fnc, this);
			}
		}else{
			printf ("ERROR Pin no definido.\n");
			exit(0);
		}
	}
	static void* blink_fnc(void * arg){
		Led* aux = (Led*)arg;
		while(aux->booleanBlink){
			usleep( 1000000/aux->speedBlink);
			aux->on();
			usleep( 1000000/aux->speedBlink);
			aux->off();
		}
		return NULL;		
	}
	void stopBlinking(){
		if( pin!= -1 ){
			booleanBlink = false;
		}else{
			printf ("ERROR Pin no definido.\n");
			exit(0);
		}
	}
	bool isBlinking(){
		return booleanBlink;
	}
	
};
#endif
