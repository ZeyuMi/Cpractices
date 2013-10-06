#include<stdio.h>
#define MAX 1024
char upperCases[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lowerCases[27] = "abcdefghijklmnopqrstuvwxyz";
char numbers[11] = "0123456789";

void expand(char s1[], char s2[]);
int findChar(char s[], char c);

int main(){
	char s[] = "-3-9x-z2a-z`";
	char s1[MAX];
	expand(s1, s);
	printf("%s", s1);
	return 0;
}

void expand(char s1[], char s2[]){
	int i, j, start, end;
	i = j = start = end = 0;
	
	while(s2[i] != '\0'){
		switch(s2[i]){
			case '-':
				if(i == 0 || s2[i+1] == '\0'){
					s1[j++] = s2[i++];
				}else{
					if((start = findChar(upperCases, s2[i-1])) != -1 && (end = findChar(upperCases, s2[i+1])) != -1){
						while(start != end){
							s1[j++] = upperCases[start];
							if(start < end)
								start++;
							else
								start--;
						}
						s1[j++] = upperCases[end];
						i += 2;
					}
					else if((start = findChar(lowerCases, s2[i-1])) != -1 && (end = findChar(lowerCases, s2[i+1])) != -1 ){
						while(start != end){
							s1[j++] = lowerCases[start];
							if(start < end)
								start++;
							else
								start--;
						}
						s1[j++] = lowerCases[end];
						i += 2;
					}
					else if((start = findChar(numbers, s2[i-1])) != -1 && (end = findChar(numbers, s2[i+1])) != -1){
						while(start != end){
							s1[j++] = numbers[start];
							if(start < end)
								start++;
							else
								start--;
						}
						s1[j++] = numbers[end];
						i += 2;
					}
					else{
						s1[j++] = s2[i-1];
						s1[j++] = s2[i];
						s1[j++] = s2[i++];
					}
				}
				break;
			default :
				if(s2[i+1] == '-' && s2[i+2] != '\0')
					i++;
				else
					s1[j++] = s2[i++];
				break;

		}
	}
	s1[j] = s2[i];
}

int findChar(char s[], char c){
	int i = 0;
	int flag = 0;
	while(s[i] != '\0'){
		if(s[i] == c){
			flag = 1;
			break;
		}
		i++;
	}
	if(flag){
		return i;
	}else
		return -1;
}
