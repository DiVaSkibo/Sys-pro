task: source.o method.o
	cc -o task source.o method.o

source.o: source.c
	cc -c source.c

method.o: method.c
	cc -c method.c

clean:
	rm -f *.o
	rm -f task
