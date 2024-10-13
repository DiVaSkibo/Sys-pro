#include "header.h"

int lowlevcreate(char* fname)
{
    int f = open(fname, O_RDWR | O_CREAT | O_TRUNC);
    ftruncate(f, FSIZE);
    return f;
}
void lowlevcopy(int f1, int f2)
{
    ssize_t len;
    char buf[BUFSIZE];
    while ((len = read(f1, buf, BUFSIZE)) > 0)
    {
        write(f2, buf, len);
    }
}

FILE* standartcreate(char* fname)
{
    FILE* f = fopen(fname, "w+");
    fseek(f, FSIZE - 1, SEEK_SET);
    fwrite("", 1, 1, f);
    fseek(f, 0, SEEK_SET);
    return f;
}
void standartcopy(FILE* f1, FILE* f2)
{
    char c;
    while ((c = fgetc(f1)) != EOF)
    {
        fputc(c, f2);
    }
}

void* mmapcreate(char* fname)
{
    int f = open(fname, O_RDWR | O_CREAT | O_TRUNC);
    ftruncate(f, FSIZE);
    void* map = mmap(0, FSIZE, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    close(f);
    return map;
}
void mmapcopy(void* map1, int f2)
{
    char buf[BUFSIZE];
    for (off_t i = 0; i < FSIZE; i+=BUFSIZE)
    {
        memcpy(buf, (char*)map1 + i, BUFSIZE);
        write(f2, buf, BUFSIZE);
    }
}
