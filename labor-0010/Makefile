Task: Source0
	./Source0


Source0: source0.o
	gcc -o Source0 source0.o

Source1: source1.o
	gcc -o Source1 source1.o

source0.o: source0.c
	gcc -c header.h source0.c

source1.o: source1.c
	gcc -c header.h source1.c

clean:
	rm -f *.o
	rm -f *.gch
	rm -f Source0
	rm -f Source1
