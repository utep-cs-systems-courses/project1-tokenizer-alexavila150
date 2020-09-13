
makefile: main.o history.o tokenizer.o
	cc main.o history.o tokenizer.o -o run

main.o: main.c history.h tokenizer.h

run: main.o
	./main.o

clean:
	rm -f *.o *# *~ output run

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c
