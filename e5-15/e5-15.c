#include <stdio.h>
#include <string.h>
#include "readlines.h"
#include "writelines.h"
#include "numcmp.h"
#include "strcmpnocase.h"

#define MAXLINE 1000
#define NOCASECMP 0
#define STRCMP 1
#define NUMCMP 2

int cmpindex = STRCMP; // strcmp is the default comparison method
int numflag = 0;
int reverseflag = 0;
int illegal = 0;

int (*cmps[3])(void* a1, void *a2) = {
	(int (*)(void *, void *))strcmpnocase,
	(int (*)(void *, void *))strcmp,
	(int (*)(void *, void *))numcmp
};

int handleParameters(int argc, char *argv[]);
void qsort(void *lines[], int left, int right, int (*cmp)(void *a1, void *a2));


int main(int argc, char *argv[]){
	if(!handleParameters(argc, argv))
		return 1;
	char *lines[MAXLINE];
	int number;
	if( (number = readlines(lines, MAXLINE)) >= 0){
		qsort((void **)lines, 0, number - 1, cmps[cmpindex]);
		writelines(lines, number);
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
	return 0;
}

int handleParameters(int argc, char *argv[]){
	int c;
	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0])
			switch(c){
				case 'n':
					cmpindex = NUMCMP;
					break;
				case 'r':
					reverseflag = 1;
					break;
				case 'f':
					cmpindex = NOCASECMP;
					break;
				default:
					illegal = 1;
					break;
			}
	}
	if(illegal){
		printf("Usage: sort -n -r\n");
		return 0;
	}else
		return 1;
}

void qsort(void *lines[], int left, int right, int (*cmp)(void *a1, void *a2)){
	int i, last;
	void swap(void *v[], int i, int j);
	if(left >= right)
		return;
	swap(lines, left, (right + left) / 2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(reverseflag)
			if((*cmp)(lines[i], lines[left]) > 0)
				swap(lines, ++last, i);
		else
			if((*cmp)(lines[i], lines[left]) < 0)
				swap(lines,++last, i);
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


