final:
	gcc -c main.c
	gcc -c scanner.c
	gcc -c transfer.c
	gcc main.o scanner.o transfer.o -o scanfer
	rm *.o
	./scanfer -s

clean:
	rm *.o 
	
