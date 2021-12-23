all: Ex3.o
	gcc -o stringProg Ex3.o
Ex3.o: Ex3.c
	gcc -c Ex3.c
clean:
	rm Ex3.o
