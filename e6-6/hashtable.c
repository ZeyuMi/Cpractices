#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define HASHSIZE 101



static struct nlist *hashtable[HASHSIZE];

unsigned hash(char *);
char *dupstr(char *);
void freenlist(struct nlist *);
void printHashtable();

//int main(){
//	install("wo","ri");
//	install("a","asdasd");
//	install("b","asdadasda");
//	printHashtable();
//	install("wo","ca");
//	printHashtable();
//	undef("wo");
//	printHashtable();
//	printf("%s",lookup("a")->name);
//	return 0;
//}

void printHashtable(){
	struct nlist *p;
	int i;
	for(i = 0;i < HASHSIZE; i++){
		if((p = hashtable[i]) != NULL){
			for(; p != NULL; p = p->next)
				printf("%s : %s, ", p->name, p->defn);
			printf("\n");
		}
	}
}

unsigned hash(char *s){
	unsigned hashval = 0;

	while(*s != '\0'){
		hashval = *s + 31 * hashval;
		s++;
	}
	return hashval % HASHSIZE;
}

char *dupstr(char *s){
	char *ns = NULL;
	if((ns = (char *)malloc(strlen(s) + 1)) == NULL)
		return NULL;
	else
		strcpy(ns, s);
	return ns;
}

struct nlist *lookup(char *name){
	unsigned hashval = hash(name);
	struct nlist *p = hashtable[hashval];
	for(; p != NULL; p = p->next){
		if(strcmp(name, p->name) == 0)
			return p;
	}
	return NULL;
}

struct nlist *install(char *name, char *defn){
	struct nlist *p = NULL;
	if((p = lookup(name)) == NULL){
		p = malloc(sizeof(struct nlist));
		if(p == NULL || (p->name = dupstr(name)) == NULL)
			return NULL;
		unsigned hashval = hash(name);
		p->next = hashtable[hashval];
		hashtable[hashval] = p;
	}else{
		free((void *)p->defn);
	}
	if((p->defn = dupstr(defn)) == NULL)
		return NULL;
	return p;
}

int undef(char *name){
	int status = 1;
	struct nlist *p = NULL;
	if((p = lookup(name)) == NULL)
		return status = 0;
	else{
		struct nlist *pp = NULL;
		unsigned hashval = hash(name);
		if(strcmp(hashtable[hashval]->name, name) == 0){
			hashtable[hashval] = hashtable[hashval]->next;	
		}else{
			for(pp = hashtable[hashval]; pp->next != NULL; pp = pp->next){
				if(strcmp(pp->next->name, name) == 0){
					pp->next = pp->next->next;
					break;
				}
			}
		}
		freenlist(p);
		return status = 1;
	}
}

void freenlist(struct nlist *p){
	if(p != NULL){
		p->next = NULL;
		free((void *)p->name);
		free((void *)p->defn);
		free((void *)p);
	}
}
