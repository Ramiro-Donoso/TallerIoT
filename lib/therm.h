#ifndef THERM_STRUCT
#define THERM_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

struct Therm{
	
	char path[50] = "/sys/bus/w1/devices/28-*/w1_slave";

	Therm(){
		/*
		FILE* file = fopen(path,"r");
		if(file==NULL){
			printf("Sensor de temperatura no reconocido.\n");
			exit(0);
		}
		fclose(file);
		*/
	}
	
	float getTemperatura(){
		FILE* fp = popen("cat /sys/bus/w1/devices/28-*/w1_slave | grep -i -o \"t=[0-9]*\" | grep -o \"[0-9]*\"", "r");
        int raw;
        fscanf(fp, "%d", &raw);
        float temp = (float)raw/1000;
        pclose(fp);
        return temp;
	}
};
#endif
