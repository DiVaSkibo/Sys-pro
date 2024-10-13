Task1: Source
	./Source 1

Task2: Source
	./Source 2

Task3: Source
	./Source 3


Source: source.o header.o
	gcc -o Source source.o header.o

source.o: source.c
	gcc -c source.c header.h

header.o: header.c
	gcc -c header.c header.h

clean:
	rm -f *.o
	rm -f *.gch
	rm -f file*
	rm -f Source
