#include<stdio.h>

int main(){
	char s = getchar();

	int a = s - '0';
	int c[a];
	c[1] = 3;
	printf("%d",*(c+1));
	return 0;
}
