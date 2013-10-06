#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>

int filecopy(int fd1, int fd2);
void error(char *name, char *formated, ...);

int main(int argc, char *argv[]){
	int fd;
	char *name = argv[0];
	if(argc == 1)
		filecopy(0, 1);
	else{
		while(--argc > 0){
			if((fd = open(*++argv,O_RDONLY, 0)) == -1)
				error(name,"cannot open file %s", *argv);
			else{
				if(filecopy(fd, 1))
					error(name,"write error on file %s", *argv);
				close(fd);
			}
		}
	}
	return 0;
}


void error(char *name, char *formated, ...){
	va_list ap;
	va_start(ap, formated);
	fprintf(stderr,"[%s] error :",name);
	vfprintf(stderr, formated,ap);
	fprintf(stderr,"\n");
	va_end(ap);
	exit(1);
}

int filecopy(int fd1, int fd2){
	char buf[1024];
	int n;
	while((n = read(fd1, buf, 1024)) > 0)
		if(write(fd2,buf,n) != n)
			return 1;
}
