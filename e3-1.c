#include<stdio.h>

int binarySearch(int x, int v[], int n);

int main(){
	int v[] = {1, 2, 3, 5, 6, 7, 8, 9, 12};
	printf("index of 7 is %d", binarySearch(7, v, sizeof(v) / sizeof(int)));
	return 0;
}

int binarySearch(int x, int v[], int n){
	int high, low, middle;
	high = n - 1;
	low = 0;
	middle = (high + low) / 2;

	while(high >= low && x != v[middle]){
		if(v[middle] > x)
			high = middle  - 1;
		else
			low = middle + 1;
		middle = (high + low) / 2;
	}
	if(x == v[middle])
		return middle;
	return -1;
}
