#include "header.h"

void bubblesort(double *arr, const int I)
{
    for (int i = 0; i < I - 1; i++)
    {
        for (int j = 0; j < I - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
void mergesort(double *arr, const int I)
{
    int start, end;
    for (int i = 1; i < I; i *= 2)
    {
        for (int j = 0; j < I - 1; j += 2 * i)
        {
            if (j + i - 1 > I - 1)
                start = I - 1;
            else
                start = j + i - 1;
            if (j + 2 * i - 1 > I - 1)
                end = I - 1;
            else
                end = j + 2 * i - 1;
            int I_left = start - j + 1, I_right = end - start;
            double arr_left[I_left], arr_right[I_right];
            for (int k = 0; k < I_left; k++)
                arr_left[k] = arr[k + j];
            for (int k = 0; k < I_right; k++)
                arr_right[k] = arr[k + start + 1];
            int k, c, x = j;
            for (k = 0, c = 0; k < I_left && c < I_right; x++)
            {
                if (arr_left[k] <= arr_right[c])
                    arr[x] = arr_left[k++];
                else
                    arr[x] = arr_right[c++];
            }
            for (k; k < I_left; k++)
                arr[x++] = arr_left[k];
            for (c; c < I_right; c++)
                arr[x++] = arr_right[c];
        }
    }
}

void *bubblethread(void *arg)
{
    thread_params *tp = (thread_params*)arg;
    tp->time = clock();
    bubblesort(tp->arr, tp->I);
    tp->time = clock() - tp->time;
    pthread_exit(NULL);
}
void *mergethread(void *arg)
{
    thread_params *tp = (thread_params*)arg;
    tp->time = clock();
    mergesort(tp->arr, tp->I);
    tp->time = clock() - tp->time;
    pthread_exit(NULL);
}
