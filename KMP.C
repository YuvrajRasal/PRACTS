#include <stdio.h>
#include <stdlib.h>
#include <string.h>

KMP(char *pat, char *txt)
{
    int i = 0;
    int j = 0;
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    LPS(pat, M, lps);
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++
        }
        if (j == M)
        {
            printf("Index of pat is %d", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}

void LPS(char *pat, int M, int *lps)
{
    int i = 1;
    int len = 0;
    lps[0] = 0;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void main()
{
    char pat[100], char txt[100];
    printf("Enter txt");
    scanf("%s", &txt);
    printf("Enter pat");
    scanf("%s", &pat);
    KMP(pat, txt);
}