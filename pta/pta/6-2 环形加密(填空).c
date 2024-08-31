#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main()
{
    char plain=0, secret=0;
    int key;
    int judge = 0;
    scanf(" %c %d", &plain, &key);
    while (key>26)
    {
        key -= 26;
    }
    while (key<-26)
    {
        key = key + 26;
    }
    judge = plain + key;
    
    if (key>0)
    {
        if (judge>122)
        {
            secret = judge - 26;
        }
        if (judge<122)
        {
            secret = judge;
        }
    }
    else
    {
        if (judge<97)
        {
            secret = judge + 26;
        }
        if (judge>97)
        {
            secret = judge;
        }
    }
        printf("%c\n", secret);
    return 0;
}