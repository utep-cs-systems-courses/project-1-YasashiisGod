CFLAGS=-g

all: lab1

tokenizer.o: tokenizer.h tokenizer.c

lab1: tokenizer.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *# *~ lab1
