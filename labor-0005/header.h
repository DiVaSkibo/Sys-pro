#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define FSIZE   6ULL * 1000 * 1000 * 1000
#define BUFSIZE 1024 * 1024

int lowlevcreate(char*);
void lowlevcopy(int, int);

FILE* standartcreate(char*);
void standartcopy(FILE*, FILE*);

void* mmapcreate(char*);
void mmapcopy(void*, int);
