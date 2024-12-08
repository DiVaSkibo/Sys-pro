#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <task number> ]\n", argv[0]);
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
            scan_dir();
            break;
        case 2:
            printf("Using family of exec calls:\n");
            if (execlp("/bin/ls", "/bin/ls", NULL, NULL) == -1)
            {
                fprintf(stderr, "{ Problem with execl... }\n");
            }
            break;
        case 3:
            printf("Using system method:\n");
            system("ls");
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