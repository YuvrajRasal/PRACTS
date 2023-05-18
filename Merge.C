#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (j = 0; j < n1; j++)
    {
        R[j] = a[m + j - 1];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[i];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m;
    m = l + (r - l) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
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
    MergeSort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Worst Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start = clock();
    MergeSort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Average Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    start = clock();
    MergeSort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);
}