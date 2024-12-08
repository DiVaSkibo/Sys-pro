Task: Source
	./Source ../


Source: source.o header.o
	gcc -o Source source.o header.o

header.o: header.c
	gcc -c header.h header.c 

source.o: source.c
	gcc -c header.h source.c 

clean:
	rm -f *.o
	rm -f *.gch
	rm -f Source
