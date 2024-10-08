#include "header.h"

void invert_case(int fdin, int fdout)
{
    int size = lseek(fdin, 0, SEEK_END);
    lseek(fdin, 0, SEEK_SET);
    char *buf = (char*)malloc(size);
    if (buf == NULL)
    {
        fprintf(stderr, "{ Problem with buffer malloc... }\n");
        return;
    }
    read(fdin, buf, size);
    for (int i = 0; buf[i] != '\0'; i++)
    {
        if (isupper(buf[i]))
        {
            buf[i] = tolower(buf[i]);
        }
        else
        {
            buf[i] = toupper(buf[i]);
        }
    }
    write(fdout, buf, size);
    free(buf);
}