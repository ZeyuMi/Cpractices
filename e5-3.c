#include<stdio.h>
#define MAX 1000

void strcat(char *s, char *t);

int main(){
	char s[MAX] = "hello,";
	char t[] = "world!";
	strcat(s, t);
	printf("%s",s);
	return 0;
}

void strcat(char *s, char *t){
	char *p = s;
	while(*p)
		p++;
	while((*p++ = *t++))
		;
}
