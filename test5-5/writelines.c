#include <stdio.h>
#include "writelines.h"

void writelines(char *lines[], int linenum){
	int i = 0;
	for(; i < linenum; i++)
		printf("%s\n", lines[i]);
}
