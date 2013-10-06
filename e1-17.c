#include<stdio.h>

#define MAXLINE 10
#define IN 1
#define OUT 0

int getLine(char line[], int maxLine);
void copyLine(char to[], char from[]);

int main(){
	char currentLine[MAXLINE];
	int length, state;
	length = 0;
	state = OUT;

	while((length = getLine(currentLine, MAXLINE)) > 0){
		if(currentLine[length-1] != '\n'){
			printf("%s",currentLine);
			state = IN;
		}else{
			if(state == IN){
				printf("%s", currentLine);
				state = OUT;
			}
		}
	}
	return 0;
}

int getLine(char line[], int maxLine){
	int i, c;

	for(i = 0; i < maxLine-1 && (c = getchar()) != EOF && c != '\n'; i++){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

void copyLine(char to[], char from[]){
	int i = 0;
	while((to[i] = from[i]) != '\0'){
		i++;
	}
}
