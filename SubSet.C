#include <stdio.h>
#include <stdlib.h>
int n, target, sum;
int set[100];
int choice[100];

void subset(int i)
{
    if (i >= n) // imp error : i<n
    {
        if (sum == target)
        {
            printf("The set of numbers giving sum %d is : { ", target);
            for (int j = 0; j < n; j++)
            {
                if (choice[j])
                {
                    printf("%d\t", set[j])
                }
            }
            printf("\n");
        }
        return;
    }
    choice[i] = 1;
    sum += set[i];
    subset(i + 1);

    choice[i] = 0;
    sum -= set[i];
    subset(i + 1);
}

void main()
{
    int i;
    printf("Enter No. of Elements\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d\n", &set[i]);
    }
    printf("Enter Target");
    scanf("%d", &target);
    sum = 0;
    subset(0);
}
