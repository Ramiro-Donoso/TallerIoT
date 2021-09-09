#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "system.h"

void pause(float seg){
		usleep((int)(seg*1000000));
}
void print(int num){
	printf("%d",num);
}
void print(float num){
	printf("%f",num);
}
void print(double num){
	printf("%lf",num);
}
void print(char letra){
	printf("%c",letra);
}
void print(char* palabra){
	printf("%s",palabra);
}
void print(const char* palabra){
	printf("%s",palabra);
}

void scan(int& num){
	scanf("%d",&num);
}
void scan(float& num){
	scanf("%f",&num);
}
void scan(double& num){
	scanf("%lf",&num);
}
void scan(char& letra){
	scanf("%c",&letra);
}
int scan(char* palabra, int size){
	palabra[0]='\0';
	fgets(palabra,size,stdin);
	int x = strlen(palabra);
	if(palabra[x-1]==10){
		palabra[x-1]='\0';
		x--;
	}
	return x;
}



