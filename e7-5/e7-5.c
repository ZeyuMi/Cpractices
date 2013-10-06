#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "gettype.h"

int main(int argc, char *argv[]){
	double operand = 0;
	double op2;
	int c;
	while((c = gettype(&operand)) != EOF){
		switch(c){
			case NUMBER:
				push(operand);
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '/':
				op2 = pop();
				push(pop() / op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			default:
				printf("error: unknown command \n");
				break;
		}
	}
	printf("answer is %lf\n", pop());
}

