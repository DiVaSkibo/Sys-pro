#include "header.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

    thread_params tpbubble1, tpmerge1, tpbubble2, tpmerge2;
    tpbubble1.I = tpmerge1.I = tpbubble2.I = tpmerge2.I = 1e5;
    tpbubble1.arr = malloc(sizeof(double) * tpbubble1.I);
    tpmerge1.arr = malloc(sizeof(double) * tpmerge1.I);
    tpbubble2.arr = malloc(sizeof(double) * tpbubble2.I);
    tpmerge2.arr = malloc(sizeof(double) * tpmerge2.I);
    for (int i = 0; i < tpbubble1.I; i++)
    {
        tpbubble1.arr[i] = tpmerge1.arr[i] = tpbubble2.arr[i] = tpmerge2.arr[i] = rand() % tpbubble1.I;
    }

    printf("\nUsing threads:\n");

    pthread_t th1, th2;
    clock_t t = clock();

    pthread_create(&th1, NULL, bubblethread, &tpbubble1);
    pthread_create(&th2, NULL, mergethread, &tpmerge1);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    t = clock() - t;

    printf("\n    Bubble sort time\t= %f", (double)tpbubble1.time / CLOCKS_PER_SEC);
    printf("\n    Merge sort time\t= %f", (double)tpmerge1.time / CLOCKS_PER_SEC);
    printf("\n    Execution time\t= %f", (double)t / CLOCKS_PER_SEC);

    
    printf("\n\nWithout using threads:\n");

    t = clock();

    tpbubble2.time = clock();
    bubblesort(tpbubble2.arr, tpbubble2.I);
    tpbubble2.time = clock() - tpbubble2.time;

    tpmerge2.time = clock();
    mergesort(tpmerge2.arr, tpmerge2.I);
    tpmerge2.time = clock() - tpmerge2.time;

    t = clock() - t;

    printf("\n    Bubble sort time\t= %f", (double)tpbubble2.time / CLOCKS_PER_SEC);
    printf("\n    Merge sort time\t= %f", (double)tpmerge2.time / CLOCKS_PER_SEC);
    printf("\n    Execution time\t= %f", (double)t / CLOCKS_PER_SEC);

    free(tpbubble1.arr);
    free(tpmerge1.arr);
    free(tpbubble2.arr);
    free(tpmerge2.arr);

    return EXIT_SUCCESS;
}