#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int main(){
	int x;
	int flag;
	if((flag = getint(&x)) != 0 && flag != EOF)
		printf("%d", x);
	else
		printf("error : not a int");
	return 0;
}

int getint(int *x){
	int c, n;
	int sign = 1;
	*x = 0;
	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != '-' && c != '+' && c != EOF){
		ungetch(c);
		return 0;
	}
	if(c == '-' || c == '+'){
		n = getch();
		if(isdigit(n)){
			sign = (c == '-') ? -1  : 1;
			c = n;
		}
		else{
			ungetch(n);
			ungetch(c);
			return 0;
		}
	}
	while(isdigit(c)){
		*x = *x * 10 + (c - '0');
		c = getch();
	}
	*x = *x * sign;
	if(c != EOF)
		ungetch(c);
	return c;
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

void ungets(char s[]){
	int i = 0, c = 0;
	while((c = s[i++])!= '\0')
		ungetch(c);
	s[i] = '\0';
}

