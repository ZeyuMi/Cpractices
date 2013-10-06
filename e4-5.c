#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXOP 100
#define NUMBER 0
#define IDENTIFIER 1

int gettop(char []);
void push(double);
double pop(void);
double top(void);
void duplicatetop();
void swaptop();
void clear();
void dealWithIdentifier(char []);

int main(){
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = gettop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case IDENTIFIER:
				dealWithIdentifier(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				push(pop() / op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		
	}
	return 0;
}

void dealWithIdentifier(char s[]){
	double op2;
	if(0 == strcmp(s, "sin")){
		push(sin(pop()));
	}else if(0 == strcmp(s , "exp")){
		push(exp(pop()));
	}else if(0 == strcmp(s, "pow")){
		op2 = pop();
		push(pow(pop(), op2));
	}else{
		printf("error: %s is not a supported function\n",s );
	}
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error : stack full, cannot push %g\n", f);
}

double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error : stack empty\n");
		return 0.0;
	}
}

double showtop(){
	if(sp > 0)
		return val[sp - 1];
	else{
		printf("error : stack empty\n");
		return 0.0;
	}
}

void duplicatetop(){
	if(sp > 0){
		double top = val[sp - 1];
		push(top);
	}else{
		printf("error : stack empty\n");
	}
}

void swaptop(){
	if(sp > 1){
		double e = pop();
		double e2 = pop();
		push(e);
		push(e2);
	}else{
		printf("error : not enough elements\n");
	}
}

void clear(){
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int gettop(char s[]){
	int i, c, n;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(isalpha(c)){
		i = 0;
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
		return IDENTIFIER;
	}

	if(!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if(c == '-'){
		n = getch();
		if(isdigit(n)){
			s[++i] = n;
			c = n;
		}
		else{
			ungetch(n);
			return c;
		}
	}
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
