#include <stdlib.h>
#include "numcmp.h"

int numcmp(char *s1, char *s2){
	double d1 = atof(s1);
	double d2 = atof(s2);
	if(d1 > d2)
		return 1;
	else if(d1 < d2)
		return -1;
	else 
		return 0;
}
