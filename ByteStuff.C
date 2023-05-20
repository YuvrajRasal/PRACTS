#include <stdio.h>
#include <conio.h>
void main()
{
    char stuff[100], str[100], Eflag, Sflag, esc;
    int ind = 1, i;
    printf("enter pattern");
    gets(str);
    printf("Enter starting flag");
    scanf("%c", &Sflag);
    printf("enter end flag");
    scanf("%c", &Eflag);
    printf("enter esc char");
    scanf("%c", &esc);

    stuff[0] = Sflag;
    for (i = 0; i < strlen(str); i++) // i= 1 or 0?
    {
        if (str[i] == Sflag || str[i] == Eflag || str[i] == esc)
        {
            stuff[ind++] = esc;
        }
        stuff[ind++] = str[i];
    }
    stuff[ind] = Eflag;
    puts(stuff);
}