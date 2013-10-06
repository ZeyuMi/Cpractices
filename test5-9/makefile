objects = test5-9.o readlines.o

find: $(objects)
	cc -o find $(objects)

test5-9.o:test5-9.c readlines.h
readlines.o:readlines.c readlines.h

.PHONY:clean
clean:
	rm find $(objects)
