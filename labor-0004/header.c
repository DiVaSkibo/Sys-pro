#include "header.h"

int scan_dir(char* dirname)
{
    DIR *dir = opendir(dirname);

    if (dir == NULL)
    {
        fprintf(stderr, "{ Directory wasn`t found... }\n");
        return 1;
    }

    struct dirent *dirent;
    char* buf;
    while ((dirent = readdir(dir)) != NULL)
    {
        if (dirent->d_type == DT_DIR)
        {
            if (strcmp(dirent->d_name, ".") && strcmp(dirent->d_name, "..") && dirent->d_name[0] != '.')
            {
                if ((buf = (char*)malloc((strlen(dirname) + strlen(dirent->d_name) + 1) * sizeof(char) + 1)) == NULL)
                {
                    fprintf(stderr, "{ Problem with buffer malloc... }\n");
                    return 1;
                }
                strcpy(buf, dirname);
                strcat(buf, "/");
                strcat(buf, dirent->d_name);
                scan_dir(buf);
                free(buf);
            }
        }
        else if (dirent->d_type == DT_REG)
        {
            char *fname = (char*)malloc((strlen(dirname) + strlen(dirent->d_name) + 1) * sizeof(char) + 1);
            if (fname == NULL)
            {
                fprintf(stderr, "{ Problem with buffer malloc... }\n");
                return 1;
            }
            strcpy(fname, dirname);
            strcat(fname, "/");
            strcat(fname, dirent->d_name);
            int f = open(fname, O_RDONLY);
            if (find_signature(f, "{ Skibo Dmytro Viacheslavovich 335a }"))
            {
                printf("%s\n", fname);
            }
        }
    }
    return 0;
}
int find_signature(int f, char* sign)
{
    int size = lseek(f, 0, SEEK_END);
    lseek(f, 0, SEEK_SET);
    char *buf = (char*)malloc(size);
    if (buf == NULL)
    {
        fprintf(stderr, "{ Problem with buffer malloc... }\n");
        return 0;
    }
    read(f, buf, size);
    if (strstr(buf, sign) != NULL)
    {
        free(buf);
        return 1;
    }
    free(buf);
    return 0;
}