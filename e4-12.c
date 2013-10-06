#include<stdio.h>
#define MAX 1024

int itoa(int x, char s[], int i);

int main(){
	char s[1024];
	itoa(-12332389, s, 0);
	printf("%s", s);
}

int itoa(int x, char s[], int i){
	if(x < 0){
		s[i++] = '-';
		x = -x;
	}
	if(x < 10)
		s[i++] = x + '0';
	else{
		i = itoa(x / 10, s, i);
		s[i++] = (x % 10) + '0';
		s[i] = '\0'; 
	}
	return i;
}
