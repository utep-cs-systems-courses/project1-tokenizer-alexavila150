
makefile: main.o history.o
	cc main.o history.o -o run

main.o: main.c history.h

run: main.o
	./main.o

clean:
	rm -f *.o *# *~ output

history.o: history.h history.c
