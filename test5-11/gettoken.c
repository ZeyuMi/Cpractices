#include <stdio.h>
#include "string.h"
#include "gettoken.h"
#define BUFSIZE 100

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int getch();
void ungetch(int);

int gettoken(void){
	int c;
	char *p = token;
	while((c = getch()) == ' ' || c == '\t')
		;
	if(isalpha(c)){
		*p++ = c;
		while(isalnum(c = getch()))
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}else if(c == '('){
		if((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		}else{
			ungetch(c);
			return tokentype = '(';
		}
	}else if(c == '['){
		*p++ = c;
		while((*p++ = c = getch()) != ']')
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}else
		return tokentype = c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(){
	return (bufp > 0) ? buf[bufp--] : getchar();
}

void ungetch(int c){
	if(bufp >= 100)
		printf("Error: buffer is full\n");
	else{
		buf[++bufp] = c;
	}
}
