#include <stdio.h>
#include <string.h>

#define MAXLEN 100
int cmpfile(FILE *, FILE*, char *, char *, int);

int main(int argc, char *argv[]){
	char line1[MAXLEN];
	char line2[MAXLEN];
	int flag;
	FILE *file1, *file2;
	if(argc == 3){
		if((file1 = fopen(argv[1],"r")) == NULL){
			fprintf(stderr, "%s:%s cannot be opened\n", argv[0],argv[1]);	
			return 1;
		}
		if((file2 = fopen(argv[2],"r")) == NULL){
			fprintf(stderr, "%s:%s cannot be opened\n",argv[0],argv[2]);
			return 1;
		}
		if((flag = cmpfile(file1,file2,line1,line2,MAXLEN)) == 1){
			printf("%s and %s are the same.\n", argv[1],argv[2]);
		}else {
			printf("the first line where they differ is as follows:\n%s:%s\n%s:%s\n",argv[1],line1,argv[2],line2);
		}
		fclose(file1);
		fclose(file2);
		return 0;
	}else{
		fprintf(stderr,"%s:Usage: cmp file1 file2\n",argv[0]);
		return 1;
	}
}

int cmpfile(FILE *file1, FILE *file2, char *line1, char *line2, int max){
	int flag = 1; //the two files are same
	int file1eof = 0;
	int file2eof = 0;

	while(1){
		if(fgets(line1,max,file1) == NULL){
			strcpy(line1,"");
			file1eof = 1;
		}
		if(fgets(line2,max,file2) == NULL){
			strcpy(line2,"");
			file2eof = 1;
		}
		if(file1eof == 1 && file2eof == 1)
			return flag = 1;
		if(strcmp(line1,line2) != 0)
			return flag = 0;
	}
	
}


