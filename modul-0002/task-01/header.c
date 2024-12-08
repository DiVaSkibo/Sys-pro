#include "header.h"

int scan_dir()
{
    DIR *dir = opendir("./");

    if (dir == NULL)
    {
        fprintf(stderr, "{ Directory wasn`t found... }\n");
        return 1;
    }

    struct dirent *dirent;
    char* buf;
    while ((dirent = readdir(dir)) != NULL)
    {
        printf("%s  ", dirent->d_name);
    }
    return 0;
}
