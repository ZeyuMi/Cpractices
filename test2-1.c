#include<stdio.h>

int a = 2;
int b = 1;
 
int test(char a[]);

int main(){
	char a[10] = "www";
	test(a);
	printf("%s", a);
}

int test(char a[]){
	a[2] = '3';
	return 1;
}
