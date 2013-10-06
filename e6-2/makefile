objects = e6-2.o getword.o searchtree.o

count : $(objects)
	cc -o count $(objects)

e6-2.o: e6-2.c getword.h searchtree.h
getword.o: getword.h getword.c
searchtree.o: searchtree.c searchtree.h

.PHONY:clean
clean:
	rm count $(objects)
