#include <stdio.h>

void main()
{
    int data[100], idealData[100], sentData[100], ch, par, i, j;
    do
    {

        printf("Enter 1 for even parity , 0 for odd parity\n");
        scanf("%d", &par);
        printf("1. Transimission\n2. Reception\n3. Exit");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter 4 bit data");
            for (i = 0; i < 4; i++)
                scanf("%d", &sentData[i]);
            data[3] = sentData[3];
            data[5] = sentData[2];
            data[6] = sentData[1];
            data[7] = sentData[0];
            if (par == 1)
            {
                data[1] = data[3] ^ data[5] ^ data[7];
                data[2] = data[3] ^ data[6] ^ data[7];
                data[4] = data[5] ^ data[6] ^ data[7];
            }
            else
            {
                data[1] = 1 - data[3] ^ data[5] ^ data[7];
                data[2] = 1 - data[3] ^ data[6] ^ data[7];
                data[4] = 1 - data[5] ^ data[6] ^ data[7];
            }
            printf("The hamming code is : ");
            for (i = 7; i > 0; i--)
                printf("%d", data[i]);
        }
        if (ch == 2)
        {
            printf("enter 7 digit hamming code : ");
            scanf("%d", &data[i]);
            if (par == 1)
            {
                idealData[1] = data[3] ^ data[5] ^ data[7] ^ data[1];
                idealData[2] = data[3] ^ data[6] ^ data[7] ^ data[2];
                idealData[4] = data[5] ^ data[6] ^ data[7] ^ data[4];
            }
            else
            {
                idealData[1] = 1 - data[3] ^ data[5] ^ data[7] ^ data[1];
                idealData[2] = 1 - data[3] ^ data[6] ^ data[7] ^ data[2];
                idealData[4] = 1 - data[5] ^ data[6] ^ data[7] ^ data[4];
            }
            int e = 4 * idealData[4] + 2 * idealData[2] + 1 * idealData[1];
            if (e == 0)
            {
                printf("No error");
            }
            else
            {
                data[e] = 1 - data[e];
                printf("Correct hamming code is : ");
                for (i = 7; i > 0; i--)
                    printf("%d", data[i]);
            }
        }
    } while (ch != 3);
}