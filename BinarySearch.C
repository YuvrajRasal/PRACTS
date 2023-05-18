// #include<conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binarySearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            return binarySearch(a, l, mid - 1, x);
        }
        else
        {
            return binarySearch(a, mid + 1, r, x);
        }
    }
    return -1;
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int i, x, n, target;
    clock_t start_t, end_t;
    double total_t;
    int a[100];
    printf("enter number of element\n");
    scanf("%d", &n);

    printf("Enter elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter number to be searched\n");
    scanf("%d", &target);

    bubbleSort(a, n);
    x = binarySearch(a, 0, n, target);
    if (x == -1)
    {
        printf("element is absent");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("%d\t", a[i]);
        }
        printf("\nelemen (%d) is found at index : %d", target, x);
    }
}