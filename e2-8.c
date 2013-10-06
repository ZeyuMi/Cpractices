#include<stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main(){
	printf("%d", rightrot(1, 1));
	return 0;
}

unsigned int rightrot(unsigned int x, int n){
	while(n > 0){
		if((x & 1) == 1){
			x = (x >> 1) | ~(~0U >> 1);
		}else{
			x = x >> 1;
		}
		n--;
	}
	return x;
}
