int main()
{
    double A[2][4] = {{1.5, 4.5, 6.2, 8.1}, {2.1, -3.5, 2.7, 9.4}};
    double E = 4.5;
    int k = 0;
    printlab();
    printf("\nA:\n");
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        for (int j = 0; j < sizeof(A[0])/sizeof(A[0][0]); j++)
        {
            printf("%g ", A[i][j]);
            if (A[i][j] < E)
            {
                k++;
            }
        }
        printf("\n");
    }
    printf("E = %g\n\n", E);

    double B[k];
    printf("B:\n");
    k = 0;
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        for (int j = 0; j < sizeof(A[0])/sizeof(A[0][0]); j++)
        {
            if (A[i][j] < E)
            {
                B[k] = A[i][j];
                printf("%g ", B[k++]);
            }
        }
    }
    printf("\n\n");
    return 0;
}