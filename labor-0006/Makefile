Task1: Source
	./Source 1 header.h

Task2: Source
	./Source 2 header.h

Task3: Source
	./Source 3 header.h


Source: source.o
	gcc -o Source source.o

source.o: source.c
	gcc -c source.c header.h

clean:
	rm -f *.o
	rm -f *.gch
	rm -f Source
