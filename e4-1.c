#include<stdio.h>
#define MAXLINE 1000


int getLine(char line[], int max);
int strIndex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
	char line[MAXLINE];
	int position;
	while(getLine(line, MAXLINE) > 0){
		if((position = strIndex(line, pattern)) >= 0){
			printf("position = %d %s",  position, line);	
		}
	}
	return 0;
}

int getLine(char line[], int max){
	int i = 0;
	int c = 0;
	while(i < (max - 1) &&  (c = getchar()) != EOF && c != '\n'){
		line[i++] = c;
	}
	if(c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}


int strIndex(char source[], char searchfor[]){
	int lastPosition = -1;
	int i, j, k;
	for(i = 0; source[i] != '\0'; i++){
		for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
			;
		if(k > 0 && searchfor[k] == '\0')
			lastPosition = i;
	}
	return lastPosition;
}
