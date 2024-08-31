#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void TimeInput(int* hour, int* minute, double* second);
void TimeOutput2(int hour, int minute, double second);

int main()
{
    int hour, minute;
    double second;
    TimeInput(&hour, &minute, &second);
    return 0;
}

void TimeInput(int* hour, int* minute, double* second)
{
    scanf("%d:%d:%lf", hour, minute, second);
    if (*hour < 12)
    {
        printf("%02d:%02d:", *hour, *minute);
        if (second < 10)
            printf("0%.2lf(AM)", *second);
        else
            printf("%.2lf(AM)", *second);
    }
    if (*hour >= 12)
    {
        *hour = *hour - 12;
        printf("%02d:%02d:", *hour, *minute);
        if (*second < 10)
            printf("0%.2lf(PM)", *second);
        else
            printf("%.2lf(PM)", *second);
    }
}


