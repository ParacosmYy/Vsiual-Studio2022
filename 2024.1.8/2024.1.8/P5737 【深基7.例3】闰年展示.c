#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int judge(int a)
{
	if (a % 400 == 0 || a % 4 == 0 && a % 100 != 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int add(int c)
{
	return c++;
}
int main()
{
	int year1 = 0;
	int year2 = 0;
	int min = 0;
	int max = 0;
	int arr[10000000] = { 0 };
	int count = 0;
    int j = -1;
	scanf("%d%d", &year1, &year2);
	if (year1 > year2)
	{
		min = year2;
		max = year1;
	}
	else if (year1 < year2)
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
		min = year1;
		max = year2;
	}
	for (int i = min; i <=max; i++)
	{
		switch (judge(i))
		{
		case 0:
			break;
		case 1:
			for ( j = add(j); j < 10000; j++)
			{                            
				arr[j] = i;
				count++;
				break;
			}
		default:
			break;
		}
	}
	printf("%d\n", count);
	for (int m = 0; m < count; m++)
	{
		printf("%d ", arr[m]);
	}
	return 0;
}