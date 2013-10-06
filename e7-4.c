#include <stdio.h>
#include <stdarg.h>

void minscanf(char *, ...);

int main(){
	int a;
	char *s;
	double c;
	minscanf("%d %s %lf",&a, s,&c);
	printf("%d %s %lf",a, s, c);
}

void minscanf(char *formated, ...){
	va_list ap;
	int *ival;
	double *dval;
	char *sval;
	char *s;
	va_start(ap,formated);
	for(s = formated; *s; s++){
		if(*s != '%')
			continue;
		switch(*++s){
		case 'd':
			ival = va_arg(ap,int *);
			scanf("%d",ival);
			break;
		case 'l':
			if(*++s == 'f'){
				dval = va_arg(ap, double *);
				scanf("%lf",dval);
			}
			break;
		case 's':
			sval = va_arg(ap, char *);
			scanf("%s",sval);
			break;
		default:
			continue;
		}
	}
	va_end(ap);
}
