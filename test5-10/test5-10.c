#include <stdio.h>
#include <string.h>
#include "readlines.h"
#include "writelines.h"
#include "numcmp.h"

#define MAXLINE 1000

void qsort(void *lines[], int left, int right, int (*cmp)(void *a1, void *a2));

int main(int argc, char *argv[]){
	int numflag = 0;
	if(argc == 2 && strcmp("-n", argv[1]) == 0)
		numflag = 1;
	char *lines[MAXLINE];
	int number;
	if( (number = readlines(lines, MAXLINE)) >= 0){
		qsort((void **)lines, 0, number - 1, (int (*)(void *, void*))(numflag ? numcmp : strcmp));
		writelines(lines, number);
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
	return 0;
}

void qsort(void *lines[], int left, int right, int (*cmp)(void *a1, void *a2)){
	int i, last;
	void swap(void *v[], int i, int j);
	if(left >= right)
		return;
	swap(lines, left, (right + left) / 2);
	last = left;
	for(i = left+1; i <= right; i++)
		if((*cmp)(lines[i], lines[left]) < 0)
			swap(lines, ++last, i);
	swap(lines, left, last);
	qsort(lines, left, last-1, cmp);
	qsort(lines, last+1, right, cmp);
}

void swap(void *v[], int i, int j){
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


