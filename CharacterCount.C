#include <stdio.h>
#include <string.h>
void main()
{
    int str[100];
    int stuff[100];
    int i = 0, j, len, ind = 0;
    printf("enter sequence");
    gets(str);
    len = strlen(str);

    while (i < strlen(str))
    {
        if (r > len && len > 0)
        {
            r = len + 1;
        }
        len = len - (r - 1);
        stuff[ind++] = r + "0";
        for (j = i; j < i + r - 1; j++)
        {
            stuff[ind++] = ind[j];
        }
        i = j;
    }
    puts(stuff);
}