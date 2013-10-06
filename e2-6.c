#include<stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(){
	printf("%d", setbits(44, 4, 2, 78));
	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y){
	unsigned right = ( y & ~(~0 << n) ) << (p - n + 1);
	unsigned left =  x & ((~0 << (p + 1) | ~(~0 << (p - n + 1))));
	return left | right;
}
