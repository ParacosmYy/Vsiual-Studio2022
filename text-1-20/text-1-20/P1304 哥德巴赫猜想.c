#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int n, x, y;
int prime(int n)
{
	if (n == 2)return 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)return 0;
	}
	return 1;

}

int fun(int n)
{
	for (int i = 2; i <=(n/2); i++)
	{
		if (prime(i)&& prime(n-i))
		{
			x = i;
			y = n - i;
			return 1;
		}
		
	}
	return 0;
}
int main()
{
	int input = 0;
	scanf("%d", &input);
	for (int i = 4; i <=input ; i+=2)
	{
		if (fun(i) == 1)
		{
				printf("%d=%d+%d\n", i, x, y);
		}
	}
	return 0;
}