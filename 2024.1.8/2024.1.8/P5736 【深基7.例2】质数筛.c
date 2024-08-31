#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Prime_sieve(int b)
{
	int a = 0;
	if (b==1)
	{
		return 1;
	}
	else if (b==2)
	{
		return 0;
	}
	else if (b == 0)
	{
		return 1;
	}
		 
	for (int i = 2; i < b; i++)
	{
		if (b % i == 0)
		{
			return 1;
		}
	}
	return 0;
}
	int main()
	{
		int n = 0;
		int arr[100000] = { 0 };
		int c = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			c = arr[i];
			switch (Prime_sieve(c))
			{
			case 0:
				printf("%d ", arr[i]);
				break;
			case 1:
				break;
			default:
				break;
			}
		}
		return 0;
	}
