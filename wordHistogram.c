#include<stdio.h>

#define IN 1
#define OUT 0

int main(){
	int i, c, counts, state;
	int wordLengths[20];

	c = counts = 0;
	state = OUT;
	for(i = 0; i < 20; i++)
		wordLengths[i] = 0;

	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			if(state == IN){
				wordLengths[counts-1]++;
				state = OUT;
				counts = 0;
			}
		}else{
			if(state == OUT){
				state = IN;
			}
			counts++;
		}
	}
	printf("lengths: ");
	for(i = 0; i < 20; i++){
		printf(" %3d", i+1);
	}
	printf("\n        ");
	for(i = 0; i < 20; i++){
		printf(" %3d", wordLengths[i]);
	}
	printf("\n");
	return 0;
}
