#include<stdio.h>

int strend(char *s, char *t);
int strlen(char *s);

int main(){
	char s[] = "himybaby";
	char t[] = "sdhim";
	printf("%d", strend(s,t));
	return 0;
}

int strend(char *s, char *t){
	if(strlen(t) > strlen(s))
		return 0;

	char *st = s;
	char *tt = t;
	while(*st)
		st++;
	while(*tt)
		tt++;
	while(*st == *tt){
		if(tt == t)
			return 1;
		st--;
		tt--;
	}
	return 0;

}

int strlen(char *s){
	char *p = s;
	while(*s++)
		;
	return s - p;
}
