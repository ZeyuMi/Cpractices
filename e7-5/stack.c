#include <stdio.h>
#include "stack.h"

#define STACKSIZE 1000

double stack[STACKSIZE];
int sp = 0;

void push(double val){
	if(sp >= 1000)
		printf("error: stack is full\n");
	else{
		stack[sp++] = val;
	}
}

double pop(void){
	if(sp == 0){
		printf("error: stack is empty\n");
		return 0.0;
	}
	else{
		return stack[--sp];
	}

}
