objects = e6-1.o getword.o

count : $(objects)
	cc -o count $(objects)

e6-1.o: e6-1.c getword.h
getword.o: getword.h getword.c

.PHONY:clean
clean:
	rm count $(objects)
