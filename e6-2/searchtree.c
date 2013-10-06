#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "searchtree.h"

int cmpfirstcharacters(char *, char *, int);
struct word *walloc(void);
char *strcopy(char *);

struct word *addtree(struct word *root, char *word, int n){
	int cmpresult = 0;
	if(root == NULL){
		root = walloc();
		root->name = strcopy(word);
		root->next = strcopy("");
		root->leftchild = NULL;
		root->rightchild = NULL;
	}else if((cmpresult = cmpfirstcharacters(root->name, word, n)) == 0){
		if(strlen(root->next) != 0)
			strcat(root->next, ",");
		strcat(root->next, word);
	}else if(cmpresult < 0){
		root->rightchild = addtree(root->rightchild, word, n);
	}else{
		root->leftchild = addtree(root->leftchild, word, n);
	}
	return root;
}

void printtree(struct word* tree){
	if(tree != NULL){
		printtree(tree->leftchild);
		printf("%s:%s\n", tree->name, (tree->next == NULL) ? "" : tree->next);
		printtree(tree->rightchild);
	}
}

int cmpfirstcharacters(char *s1, char *s2, int n){
	if(n < 0)
		return strcmp(s1,s2);
	while(n-- > 0 && *s1 != '\0' && *s2 != '\0'){
		if(*s1 > *s2)
			return 1;
		else if(*s1 < *s2)
			return -1;
		else{
			s1++;
			s2++;
		}
	}
	if(n == -1)
		return 0;
	else if(*s1 == '\0' && *s2 == '\0')
		return 0;
	else if(*s1 == '\0')
		return -1;
	else 
		return 1;
}

struct word *walloc(void){
	return (struct word*)malloc(sizeof(struct word));
}

char *strcopy(char *word){
	char *p;
	p = (char *)malloc(strlen(word)+1);
	if(p != NULL)
		strcpy(p,word);
	return p;
}

