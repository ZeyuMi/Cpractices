#include <stdio.h>
#include "dcl.h"
#include "gettoken.h"

int main(){
	while(gettoken() != EOF){
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if(tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
}
