Task: Source
	./Source ../


Source: source.o header.o
	gcc -o Source source.o header.o

source.o: source.c
	gcc -c header.h source.c 

header.o: header.c
	gcc -c header.h header.c 

clean:
	rm -f *.o
	rm -f *.gch
	rm -f Source
