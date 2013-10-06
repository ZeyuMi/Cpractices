#include <stdio.h>
#include <string.h>
#include "readlines.h"

//int main(){
//	char *lines[10];
//	int num = readlines(lines, 10);
//	int i;
//	for(i = 0; i < num; i++)
//		printf("%s\n", lines[i]);
//	return 0;
//}

int readlines(char *lines[], int linesnum){
		int len, nlines;
		char *p, line[MAXLEN];

		nlines = 0;
		while((len = getLine(line, MAXLEN)) > 0){
			if(nlines >= linesnum || (p = alloc(len)) == NULL)
				return -1;
			else{
				line[len - 1] = '\0';
				strcpy(p, line);
				lines[nlines++] = p;
			}
		}
		return nlines;
}

int getLine(char *line, int len){
	char c;
	int now = 0;
	for(; len > 0 && (c  = getchar()) != '\n' && c != EOF; line++, len--, now++)
		*line = c;
	if(c == '\n'){
		*line = c;
		now++;
		line++;
	}
	*line = '\0';
	return now;
}

#define BUFSIZE 5000
static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if(allocbuf + BUFSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}else{
		return 0;
	}
}

