objects = readlines.o writelines.o test5-10.o numcmp.o

sort : $(objects)
	cc -o sort $(objects)

readlines.o : readlines.c readlines.h
writelines.o : writelines.c writelines.h
test5-10.o : test5-10.c readlines.h writelines.h numcmp.h
numcmp.0: numcmp.c numcmp.h

.PHONY : clean
clean:
	rm sort $(objects)
