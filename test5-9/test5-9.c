#include <stdio.h>
#include <string.h>
#include "readlines.h"

#define MAXLINE 1000
int number = 0;
int except = 0;
int illegal = 0;

int main(int argc, char *argv[]){
	int c;
	int linenumber = 0;
	char line[MAXLINE];
	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++(*argv))
			switch(c){
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find : illegal option %c\n", c);
					illegal = 1;
					break;
			}
	if(illegal == 1)
		printf("Usage: find -x -n pattern\n");
	else{
		while(getLine(line, MAXLINE) > 0){
			linenumber++;
			if((strstr(line, *argv) != NULL) != except){
				if(number)
					printf("%d:", linenumber);
				printf("%s",line);
			}
		}
	}

	return 0;
}
