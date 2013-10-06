objects = readlines.o writelines.o test5-5.o

sort : $(objects)
	cc -o sort $(objects)

readlines.o : readlines.c readlines.h
writelines.o : writelines.c writelines.h
test5-5.o : test5-5.c readlines.h writelines.h

.PHONY : clean
clean:
	rm sort $(objects)
