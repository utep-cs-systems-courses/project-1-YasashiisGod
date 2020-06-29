CFLAGS=-g

all: lab1

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h tokenizer.h history.c

main.o: tokenizer.h main.c history.h

lab1: main.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *# *~ lab1
