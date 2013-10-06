#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getword.h"

struct key{
	char *name;
	int count;
} keytab[] = {
	"auto",0,
	"break",0,
	"case",0,
	"char",0,
	"const",0,
	"continue",0,
	"default",0,
	"do",0,
	"double",0,
	"else",0,
	"enum",0,
	"extern",0,
	"float",0,
	"for",0,
	"goto",0,
	"if",0,
	"int",0,
	"long",0,
	"register",0,
	"return",0,
	"short",0,
	"signed",0,
	"sizeof",0,
	"static",0,
	"struct",0,
	"switch",0,
	"typedef",0,
	"union",0,
	"unsigned",0,
	"void",0,
	"volatile",0,
	"while",0,
};

int tablelen = sizeof keytab / sizeof keytab[0];

int binarysearch(char *, struct key *, int);

int main(){
	int n;
	char word[MAXLEN];
	while(getword(word, MAXLEN) != EOF){
		n = binarysearch(word, keytab, tablelen);
		if(n != -1)
			keytab[n].count++;
	}
	for(n = 0; n < tablelen; n++){
		printf("%s : %d\n", keytab[n].name, keytab[n].count);
	}
	return 0;
}

int binarysearch(char *word, struct key *keytab, int n){
	int left, right, middle;
	int cmpresult;
	left = 0, right = n-1;
	while(left <= right){
		middle = (left + right) / 2;
		if((cmpresult = strcmp(word, keytab[middle].name)) < 0)
			right = middle - 1;
		else if(cmpresult > 0)
			left = middle + 1;
		else 
			return middle;
	}
	return -1;
}




