objects = gettoken.o test5-11.o dcl.o

dcl: $(objects)
	cc -o dcl $(objects)

gettoken.o : gettoken.c gettoken.h
dcl.o : dcl.c dcl.h gettoken.h
test5-11.o : test5-11.c gettoken.h dcl.h

.PHONY:clean
clean:
	mv dcl $(objects)
