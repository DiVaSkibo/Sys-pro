#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "{ Not enough arguments... }\n");
        printf("[ Waited for: %s <directory> ]\n", argv[0]);
        return 1;
    }

    char* fname1 = "file1";
    char* fname2 = "file2";
    clock_t tcr, tco;
    switch (atoi(argv[1]))
    {
    case 1:
        printf("Low-level method:\n");
        tcr = clock();
        int f11 = lowlevcreate(fname1);
        tcr = clock() - tcr;
        int f12 = open(fname2, O_WRONLY | O_TRUNC | O_CREAT);
        tco = clock();
        lowlevcopy(f11, f12);
        tco = clock() - tco;
        close(f11);
        close(f12);
        break;
    case 2:
        printf("Standart method:\n");
        tcr = clock();
        FILE* f21 = standartcreate(fname1);
        tcr = clock() - tcr;
        FILE* f22 = fopen(fname2, "w");
        tco = clock();
        standartcopy(f21, f22);
        tco = clock() - tco;
        fclose(f21);
        fclose(f22);
        break;
    case 3:
        printf("Mmap method:\n");
        tcr = clock();
        void* f31 = mmapcreate(fname1);
        tcr = clock() - tcr;
        int f32 = open(fname2, O_WRONLY | O_TRUNC | O_CREAT);
        tco = clock();
        mmapcopy(f31, f32);
        tco = clock() - tco;
        munmap(f31, FSIZE);
        close(f32);
        break;
    default:
        fprintf(stderr, "{ There is no task %s... }\n", argv[1]);
        return 1;
    }

    printf("  Creation time\t= %f\n", (double)tcr / CLOCKS_PER_SEC);
    printf("  Copy time\t= %f\n", (double)tco / CLOCKS_PER_SEC);

    return 0;
}