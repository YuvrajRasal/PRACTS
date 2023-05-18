#include <stdio.h>
#include <stdlib.h>

Search(char *pat, char *txt, int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int d = 256;

    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }
    for (i = 0; i < M; i++)
    {
        p = ((p * d) + pat[i]) % q;
        t = ((t * d) + txt[i]) % q;
    }

    for (i = 0; i < N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == M)
            {
                printf("Pattern found at index %d", i);
            }
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]);
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

void main()
{
    int q = 101;                  // a prime no.
    char pat[100], char txt[100]; // dont write int
    printf("Enter text");
    scanf("%s", &txt);
    printf("Enter pattern");
    scanf("%d", &pat);
    Search(pat, txt, q);
}