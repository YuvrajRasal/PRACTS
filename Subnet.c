#include <stdio.h>
#include <string.h>

void main()
{
    int o1, o2, o3, o4;
    printf("Enter ip adress in (xxx.xxx.xxx.xxx) format\n");
    scanf("%d.%d.%d.%d", &o1, &o2, &o3, &o4);
    if (o1 >= 0 && o1 < 128)
    {
        printf("Class A\n");
        printf("mask : 255.0.0.0");
    }
    else if (o1 >= 128 && o2 < 192)
    {
        printf("Class B\n");
        printf("mask : 255.255.0.0");
    }
    else if (o1 >= 192 && o2 < 224)
    {
        printf("Class C\n");
        printf("mask : 255.255.255.0");
    }
    else if (o1 >= 192 && o2 < 224)
    {
        printf("Class D\n");
    }
    else if (o1 >= 224 && o2 < 240)
    {
        printf("Class E\n");
    }
}