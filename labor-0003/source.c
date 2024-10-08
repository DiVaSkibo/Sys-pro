#include "header.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <input file> <output file> ]\n", argv[0]);
        return 1;
    }

    int
        fdin = open(argv[1], O_RDONLY),
        fdout = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT);
    if (fdin == -1)
    {
        fprintf(stderr, "{ File %s wasn`t found... }\n", argv[1]);
    }
    if (fdin == -1)
    {
        close(fdin);
        close(fdout);
        return 1;
    }

    invert_case(fdin, fdout);

    int size = lseek(fdin, 0, SEEK_END);
    pwrite(fdout, "{ Skibo Dmytro Viacheslavovich 335a }", 37, size / 2);

    close(fdin);
    close(fdout);
    return EXIT_SUCCESS;
}