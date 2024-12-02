#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s ]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int
        shm_id = shmget(IPC_PRIVATE, SHMEM_SIZE, IPC_CREAT | IPC_EXCL | 0600),
        shm_size;
    char
        *shm_buf = (char*)shmat(shm_id, NULL, 0),
        *msg = "{ Skibo Dmytro Viacheslavovich 335a }";
    struct shmid_ds ds;

    if (shm_id == -1)
    {
        perror("{ Problem with shmget... }\n");
        return EXIT_FAILURE;
    }
    if (shm_buf == (char*)-1)
    {
        perror("{ Problem with shmat... }\n");
        return EXIT_FAILURE;
    }
    shmctl(shm_id, IPC_STAT, &ds);
    shm_size = ds.shm_segsz;
    if (shm_size < strlen(msg))
    {
        fprintf(stderr, "{ Problem with segsize = %d... }\n", shm_size);
        return EXIT_FAILURE;
    }
    strcpy(shm_buf, msg);
    printf("ID: %d\n", shm_id);
    printf("Press <Enter> to exit...");
    fgetc(stdin);
    shmdt(shm_buf);
    shmctl(shm_id, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}