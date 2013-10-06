#include <stdio.h>
#include <string.h>
#include "getword.h"
#include "hashtable.h"

int getmyword(char *, int);
char out[10000];
int flag = 0;
int main(){
	char name[MAXLEN];
	char defn[MAXLEN];
	struct nlist *p;
	while(getmyword(name, MAXLEN) != EOF){
		if(strcmp(name, "#") == 0){
			flag = 1;
			getmyword(name,MAXLEN);
			if(strcmp(name, "define") == 0){
				getmyword(name,MAXLEN);
				getmyword(defn,MAXLEN);
				install(name, defn);
				getword(name,MAXLEN); //this newline is useless;
			}else{
				strcat(out,"#");
				while(strcmp(name,"\n") != 0){
					strcat(out,name);
					getword(name, MAXLEN);
				}
			}
			flag = 0;
		}else if((p = lookup(name)) != NULL){
			strcat(out,p->defn);
		}else if(strcmp(name, "\n") == 0){
			printf("%s\n",out);
			out[0] = '\0';
		}else{
			strcat(out,name);
		}
	}
	return 0;		
}		


int getmyword(char *w, int n){
	int type = 0;
	while((type = getword(w,n)) == BLANK)
		if(!flag)
			strcat(out,w);
	return type;
}
