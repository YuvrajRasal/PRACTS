#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selection(int a[], int n)
{
    int i, min, j, temp = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void main()
{
    int n = 1000, i;
    int a[10000];
    clock_t start, end;
    double time_taken;
    // printf("enter number of element");
    // scanf("%d", &n);

    // printf("Enter elements");
    // for ( i = 0; i < n; i++)
    // {
    //     scanf("%d",&a[i]);
    // }

    printf("Best Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    start = clock();
    selection(a, n);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Worst Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start = clock();
    selection(a, n);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Average Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    start = clock();
    selection(a, n);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);
}