#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	int temp = 0;
	int arr[100] = { 0 };
	scanf("%d%d", &n, &m);
	temp = m;
	for (int i = 1; i <=n; i++)
	{
		arr[i] = i;
	}
	while (1)
	{
		int count = m;
		if (temp >= n)
		{
			temp = temp - n;
			while (1)
			{
	
				if (arr[temp] == 0)
				{
					temp++;
				}
			
				else if (arr[temp] && count == m)
				{
					printf("%d ", arr[temp]);
					arr[temp] = 0;
					count = 0;
					count++;
				}
				else if (arr[temp] != 0)
				{
					count++;
					temp++;
				}
				if (count == m)
				{
					break;
				}
			}
		}
		if (arr[temp] != 0)
		{
			printf("%d ", arr[temp]);
		}
		arr[temp] = 0;
		temp = temp + m;
	}
	return 0;
}