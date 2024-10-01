Task1: Source
	./Source 1 writeit.txt readit.txt
Task2: Source
	./Source 2 writeit.txt readit.txt
Task3: Source
	./Source 3 writeit.txt readit.txt
Task4: Source
	./Source 4 writeit.txt readit.txt
Task5: Source
	./Source 5 writeitcyrillic.txt readit.txt

Source: source.o header.o
	gcc -o Source source.o header.o

source.o: source.c
	gcc -c source.c

header.o: header.c
	gcc -c header.c header.h

clean:
	rm -f *.o
	rm -f Source
