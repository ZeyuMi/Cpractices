#include<stdio.h>

void shellsort(int v[], int n);

int main(){
	int v[] = {7,6,3,4,5,1,6,98,34,2,54,212};
	shellsort(v, sizeof(v) / sizeof(int));
	for(int i = 0; i < sizeof(v) / sizeof(int); i++)
		printf(" %d ", v[i]);
}

void shellsort(int v[], int n){
	for(int gap = n / 2; gap > 0; gap /= 2)
		for(int i = gap; i < n; i++)
			for(int j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
				int temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}
