Task: Source
	./Source writeit.txt readit.txt


Source: source.o header.o
	gcc -o Source source.o header.o

source.o: source.c
	gcc -c source.c header.h

header.o: header.c
	gcc -c header.c header.h

clean:
	rm -f *.o
	rm -f Source
