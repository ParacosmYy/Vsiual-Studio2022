#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int rate(int day)
{
	int count = 1;
	for (int i = 0; i < day-1; i++)
	{
		count = count + 1;
		count = count * 2;
	}
	return count;
}
int main()
{
	int day = 0;
	scanf("%d", &day);
	printf("%d", rate(day));
	return 0;
}