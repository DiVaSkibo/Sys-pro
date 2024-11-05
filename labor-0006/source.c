#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <task number> <fule name> ]\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    clock_t t = clock();
    if (pid == -1)
    {
        fprintf(stderr, "{ Problem with fork... }\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        switch (atoi(argv[1]))
        {
        case 1:
            printf("Using program code of the parent program:\n");
            ssize_t len;
            int fd = open(argv[2], O_RDONLY);
            if (fd == -1)
            {
                fprintf(stderr, "{ File wasn`t found... }\n");
                close(fd);
                return EXIT_FAILURE;
            }
            int size = lseek(fd, 0, SEEK_END);
            lseek(fd, 0, SEEK_SET);
            char* buf = (char *)malloc(size);
            if (buf == NULL)
            {
                fprintf(stderr, "{ Problem with buffer... }\n");
                close(fd);
                return EXIT_FAILURE;
            }
            read(fd, buf, size);
            printf("%s", buf);
            free(buf);
            close(fd);
            break;
        case 2:
            printf("Using family of exec calls:\n");
            if (execlp("/bin/cat", "/bin/cat", argv[2], NULL) == -1)
            {
                fprintf(stderr, "{ Problem with execl... }\n");
            }
            break;
        case 3:
            printf("Using system method:\n");
            char* cmnd = malloc(3 + strlen(argv[2] + 1));
            strcat(cmnd, "cat ");
            strcat(cmnd, argv[2]);
            printf("%s\n", cmnd);
            system(cmnd);
            free(cmnd);
            break;
        default:
            fprintf(stderr, "{ There is no task %s... }\n", argv[1]);
            return EXIT_FAILURE;
        }
    }
    else
    {
        wait(NULL);
        t = clock() - t;
        printf("\n  Execution time = %f\n", (double)t / CLOCKS_PER_SEC);
    }
    return EXIT_SUCCESS;
}