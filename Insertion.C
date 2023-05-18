#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n)
{
    int i, j, temp = 0;
    for (i = 1; i <= n - 1; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > a[temp])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

void main()
{
    int n, i;
    int a[1000];
    clock_t start, end;
    double time_taken;
    printf("enter number of element");
    scanf("%d", &n);
    // printf("Enter elements");
    // for ( i = 0; i < n; i++)
    // {
    //     scanf("%d",&a[i]);
    // }

    printf("Best Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = i = 1;
    }
    start = clock();
    insertion(a, n);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Worst Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    start = clock();
    insertion(a, n);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);

    printf("Average Case timming : ");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    start = clock();
    insertion(a, n);
    end = clock();
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("%f\n", time_taken);
}