#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int a = 20;
    int b = 1;
    int c = 0;
    int d = 0;
    while (a!=0)
    {
        c = a+c;
        a = a / 2;
        if (a==5)
        {
            d = 1;
            a = 4;
            c = c + 1;
        }
        
    }
    printf("%d", c);
    return 0;
}