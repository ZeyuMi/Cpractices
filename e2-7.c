#include<stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main(){
	printf("%d", invert(76, 4, 3));
}

unsigned int invert(unsigned int x, int p, int n){
	unsigned int mask1 = (~(~0 << (p + 1))) & (~0 << (p + 1 - n));
	unsigned int mask2 = ~mask1;
	return (x & mask2) | (x ^ mask1);
}
