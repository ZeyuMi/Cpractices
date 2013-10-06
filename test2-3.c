#include<stdio.h>

unsigned getBits(unsigned x, int p, int n);

int main(){
	printf("%d", getBits(32, 5, 3));

}

unsigned getBits(unsigned x, int p, int n){
	return (x >> (p + 1 - n)) & ~(1 << n);
}
