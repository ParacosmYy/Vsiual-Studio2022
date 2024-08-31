#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0, m = 0, q = 0;
	int r = 0, c = 0;
	int x = 0 , y = 0;
	int i = 0;
	int j = 0;
	int count = 0;

	int temp = 0;
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	int sum[100] = {0};
	int arr[100][100] = { 0 };
	int arr1[100][100] = { 0 };
	scanf("%d%d%d", &n, &m, &q);
	while (1)
	{
		scanf("%d", &arr[r][c]);
		c++;
		if (c == m - 1)
		{
			c = 0;
			r++;
		}
		if (r == n )
		{
			break;
		}
	}
	while (1)
	{
		scanf("%d" ,&arr1[x][y]);
		y++;
		if (y == 3)
		{
			x++;
		}
		if (x == q)
		{
			break;
		}
	}
	while (1)
	{
		temp = arr1[i][j];
		temp1 = arr1[i][j + 1];
		j = j + 2;
		temp2 = arr1[i][j];
		temp3 = arr1[i][j + 1];
		sum[count] = sum[count] + arr[temp][temp1];
		temp1++;
		if (temp1 == m - 1)
		{
			temp++;
			temp1 = arr1[i][j - 1];
		}
		if (temp == (temp2 + 1))
		{
			printf("%d\n", sum[count]);
			 temp = 0;
			 temp1 = 0;
			 temp2 = 0;
			 temp3 = 0;
			count++;
		}
	}
	return 0;
}