#include <stdio.h>
#include <string.h>
#include "readlines.h"
#include "writelines.h"

#define MAXLINE 1000

void qsort(char *lines[], int left, int right);

int main(){
	char *lines[MAXLINE];
	int number;
	if( (number = readlines(lines, MAXLINE)) >= 0){
		qsort(lines, 0, number - 1);
		writelines(lines, number);
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

void qsort(char *lines[], int left, int right){
	int i, last;
	void swap(char *v[], int i, int j);
	if(left >= right)
		return;
	swap(lines, left, (right + left) / 2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(lines[i], lines[left]) < 0)
			swap(lines, ++last, i);
	swap(lines, left, last);
	qsort(lines, left, last-1);
	qsort(lines, last+1, right);
}

void swap(char *v[], int i, int j){
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


