#include <stdio.h>
#include <ctype.h>
#include "getword.h"

enum tokentype {WORD = 1, QUAT, LBCOMMENT, RBCOMMENT, LCOMMENT, PREPROMARK, NEWLINE};
int flagnow = 0;

int gettoken(char *, int);

int getword(char *w, int n){
	int flag = WORD;
	int found = 0;
	while(!found){
		flag = gettoken(w, n);
		switch(flag){
		case QUAT:
			if(flagnow == QUAT)
				flagnow = 0;
			else if(flagnow == 0)
				flagnow = QUAT;
			break;
		case LBCOMMENT:
			if(flagnow == 0)
				flagnow = LBCOMMENT;
			break;
		case RBCOMMENT:
			if(flagnow == LBCOMMENT)
				flagnow = 0;
			break;
		case LCOMMENT:
			if(flagnow == 0)
				flagnow = LCOMMENT;
			break;
		case PREPROMARK:
			if(flagnow == 0)
				flagnow = PREPROMARK;
			break;
		case NEWLINE:
			if(flagnow == LCOMMENT || flagnow == PREPROMARK)
				flagnow = 0;
			break;
		case WORD:
			if(flagnow == 0){
				found = 1;
				break;
			}
			break;
		case EOF:
			return EOF;
		default:
			break;
		}
	}
	return 0;
}

int getch(void);
void ungetch(int);

int gettoken(char *w, int lim){
	int type = WORD;
	int c;
	while(isspace(c = getch()) && c != '\n')
		;
	if(c == '\\'){
		*w++ = c;
		c = getch();
		*w++ = c;
		if(c == '*'){
			type =  LBCOMMENT;
		}else if(c == '\\'){
			type =  LCOMMENT;
		}
	}else if(c == '\"'){
		*w++ = c;
		type = QUAT; 
	}else if(c == '*'){
		*w++ = c;
		c = getch();
		if(c == '\\'){
			*w++ = c;
			type = RBCOMMENT;
		}else
			ungetch(c);
	}else if(c == '#'){
		*w++ = c;
		type = PREPROMARK;
	}else if(c == '\n'){
		*w++ = c;
		type = NEWLINE;
	}else if(isalpha(c)){
		*w++ = c;
		while(--lim > 0 && (isalnum(c = getch()) || c == '_')){
			*w++ = c;
		}
		ungetch(c);
	}else
		return c;
	*w = '\0';
	return type;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("error: buffer is full\n");
	else{
		buf[bufp++] = c;
	}
}
