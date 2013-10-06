#include <stdio.h>
#include <stdarg.h>

void minprintf(char *formated, ...);
int main(){
	printf("%d\n",123);
	printf("%f\n",12.32);
	printf("worini%d,shss\n",1232);
	printf("%s","xixixi");
}

void minprintf(char *formated, ...){
	va_list ap;
	int ival;
	double dval;
	char *sval;
	
	char *p;
	va_start(ap,formated);
	for(p = formated; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
		case 'd':
			ival = va_arg(ap,int);
			printf("%d",ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f",dval);
			break;
		case 's':
			for(sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}
