objects = e7-5.o gettype.o stack.o

calculate: $(objects)
	cc -o calculate $(objects)

e7-5.o: e7-5.c stack.h gettype.h
gettype.o:gettype.c gettype.h
stack.o:stack.c stack.h

.PHONY:clean
clean:
	rm calculate $(objects)

