#include <stdio.h>
#include <ctype.h>
#include <string.h>

int flag = 0;
int illegal = 0;
int main(int argc, char *argv[]){
	int (*convert[2])(int) = {tolower, toupper};
	if(argc == 2){
		if(strcmp(argv[1],"l") == 0)
			flag = 0;
		else if(strcmp(argv[1],"u") == 0)
			flag = 1;
		else
			illegal = 1;
	}else
		illegal = 1;
	if(illegal == 1){
		printf("Usage: convert l/u\n");
		return 1;
	}
	int c;
	while((c = getchar()) != EOF){
		putchar((*convert[flag])((char)c));
	}
	return 0;
}	
