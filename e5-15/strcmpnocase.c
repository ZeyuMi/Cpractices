#include <stdio.h>
#include <string.h>
#include "strcmpnocase.h"

int strcmpnocase(char *s1, char *s2){
	char c1, c2;
	while((c1 = *s1) != '\0' && (c2 = *s2) != '\0'){
		if(c1 >= 'A' && c1 <= 'Z' && c2 >= 'a' && c2 <= 'z')
			c2 = c2 - ('a' - 'A');
		if(c1 >= 'a' && c1 <= 'z' && c2 >= 'A' && c2 <= 'Z')
			c1 = c1 - ('a' - 'A');
		if(c1 > c2)
			return 1;
		else if(c1 < c2)
			return -1;
		else{
			s1++;
			s2++;
		}
	}
	if(*s1 == '\0' && *s2 == '\0')
		return 0;
	else if(*s1 == '\0')
		return -1;
	else
		return 1;
}

