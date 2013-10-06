#include<stdio.h>

#define swap(t, x, y) t temp = x; x = y; y = temp;

int main(){
	int x,y;
	x = 3;
	y = 4;
	swap(int, x, y );
	printf("x=%d\ny=%d",x,y);
	return 0;
}
