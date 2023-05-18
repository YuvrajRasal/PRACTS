#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int a[], int l, int h)
{
    int j, temp = 0;
    int pivot = a[h];
    int i = l - 1;

    for (j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[h];
    a[h] = temp;

    return (i + 1);
}

void QuickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int pi;
        pi = partition(a, l, h);
        QuickSort(a, l, pi - 1);
        QuickSort(a, pi + 1, h);
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
    QuickSort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Worst Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start = clock();
    QuickSort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Average Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    start = clock();
    QuickSort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);
}