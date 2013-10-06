#include<stdio.h>

int main(){
	char p[] = "hello!";
	*(p+2) = '5';

	printf("%s", p);

}
