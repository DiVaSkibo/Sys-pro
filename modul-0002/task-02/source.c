#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <directory> ]\n", argv[0]);
        return 1;
    }
    
    t = clock();
    struct sigaction act;
    sigemptyset(&act.sa_mask);
    act.sa_handler = &sighandler;
    act.sa_flags = 0;
    if (sigaction(SIGINT, &act, NULL) == -1)
    {
        perror("{ Problem with sigaction... }\n");
        return 1;
    }
    
    do
    {
        scan_dir(argv[1]);
    } while (1);
    
    return 0;
}