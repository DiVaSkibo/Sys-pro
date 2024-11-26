#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <directory> ]\n", argv[0]);
        return 1;
    }

    return scan_dir(argv[1]);
}