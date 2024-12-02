#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <directory> ]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int shm_id = atoi(argv[1]);
    char *shm_buf = (char*)shmat(shm_id, 0, 0);
    if (shm_buf == (char*)-1)
    {
        perror("{ Problem with shmat... }\n");
        return EXIT_FAILURE;
    }
    printf("Message: %s\n", shm_buf);
    shmdt(shm_buf);
    
    return EXIT_SUCCESS;
}