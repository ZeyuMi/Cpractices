#include <ctype.h>
#include <stdio.h>
#include "gettype.h"

#define NUMBER 0

int gettype(double *s){
	if(scanf("%lf",s) == 1)
		return NUMBER;
	else{
		return getchar();
	}
}


