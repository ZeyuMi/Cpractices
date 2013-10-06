objects = e6-6.o getword.o hashtable.o

preprocess : $(objects)
	cc -o preprocess $(objects)

e6-6.o: e6-6.c getword.h hashtable.h
getword.o: getword.h getword.c
hashtable.o: hashtable.c hashtable.h

.PHONY:clean
clean:
	rm preprocess $(objects)
