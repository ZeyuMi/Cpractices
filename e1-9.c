#include<stdio.h>

int main(){
	int c;
	long newlineNum = 0;
	while((c = getchar()) != EOF){
		if(c == '\n')
			++newlineNum;
	}
	printf("the number of newline is %ld", newlineNum);
	return 0;
}
