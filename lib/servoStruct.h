#ifndef SERVO_STRUCT
#define SERVO_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "gpioStruct.h"

struct Servo: Pin{
	int speedMax = 5000;
	int speedMin = 100000;
	int speed; // de 1 a 100
	int pos; //grado de 0 a 180
	
	Servo(int x):Pin(x){
		speed = speedMin; 
	}
	
	void grado(int g){
		//0º->500
		//180º->2500
		pos=g;
		int x=(int)(2000.0f/180*g+500);
		on();
		usleep(x);
		off();	
	}	
	void moveTo(int g){
		if(pos<g)
			for (int i=pos;i<=g;i++){
				grado(i);
				usleep(speed);
			}
		else{
			for (int i=pos;i>g;i--){
				grado(i);
				usleep(speed);
			}			
		}
	}
	void setSpeed(int s){
		s=100-s+1;
		speed = (speedMin-speedMax)/100*s+speedMax;
	}
};
#endif
