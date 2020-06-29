CFLAGS=-g

all: lab1

tokenizer.o: tokenizer.h tokenizer.c

main.o: tokenizer.h main.c

lab1: main.o tokenizer.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *# *~ lab1
