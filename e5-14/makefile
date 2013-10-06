objects = readlines.o writelines.o e5-14.o numcmp.o

sort : $(objects)
	cc -o sort $(objects)

readlines.o : readlines.c readlines.h
writelines.o : writelines.c writelines.h
e5-14.o : e5-14.c readlines.h writelines.h numcmp.h
numcmp.0: numcmp.c numcmp.h

.PHONY : clean
clean:
	rm sort $(objects)
