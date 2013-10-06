#include<stdio.h>

int htoi(const char s[]);
int hexElementToInt(char c);

int main(){

	char s[10] = "0xa5";
	
	printf("%d", htoi(s));
}

int htoi(const char s[]){
	int i, invalid, answer, temp;
	i = invalid = answer = temp = 0;

	if(s[i] == '0'){
		i++;
		if(s[i] == 'x' || s[i] == 'X'){
			i++;
		}else{
			invalid = 1;
		}
	}else{
		invalid = 1;
	}
	
	while(!invalid && s[i] != '\0'){
		answer = answer * 16;
		temp = hexElementToInt(s[i]);
		if(temp == 0){
			invalid = 1;
		}else{
			answer += temp;
		}
		i++;
	}

	if(invalid)
		return 0;

	return answer;
}

int hexElementToInt(char c){
	int returnedValue, i;
	returnedValue = 0;
	char dict[] = "aAbBcCdDeEfF";

	if(c > '0' && c <= '9'){
		returnedValue = c - '0';
	}else{
		for(i = 0; returnedValue == 0 && dict[i] != '\0'; i++){
			if(dict[i] == c){
				returnedValue = 10 + i / 2;
			}
		}
	}

	return returnedValue;
}
