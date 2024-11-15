#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

typedef struct
{
    double *arr;
    int I;
    double time;
}   thread_params;

void bubblesort(double*, const int);
void mergesort(double*, const int);

void *bubblethread(void*);
void *mergethread(void*);
