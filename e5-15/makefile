objects = readlines.o writelines.o e5-15.o numcmp.o strcmpnocase.o

sort : $(objects)
	cc -o sort $(objects)

readlines.o : readlines.c readlines.h
writelines.o : writelines.c writelines.h
e5-15.o : e5-15.c readlines.h writelines.h numcmp.h
numcmp.o: numcmp.c numcmp.h
strcmpnocase.o: strcmpnocase.h strcmpnocase.h

.PHONY : clean
clean:
	rm sort $(objects)
