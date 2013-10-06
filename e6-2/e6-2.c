#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getword.h"
#include "searchtree.h"

int main(int argc, char *argv[]){
	int firstnum = 0;
	int illegal = 0;
	if(argc == 2){
		if(!(firstnum = atoi(argv[1]))){
			illegal = 1;
		}
	}else
		illegal = 1;
	if(illegal){	
		printf("Usage: count 3\n");
		return 1;
	}
	struct word* root = NULL;
	char word[100];
	while(getword(word, 100) != EOF){
		root = addtree(root, word, firstnum);
	}
	printtree(root);
	return 0;
}
