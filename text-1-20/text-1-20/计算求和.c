#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0;
	int sum = 0;
	int temp = 0;
	scanf("%d", &a);
	for (int i = 4; i >= 0; i--)
	{
		temp=pow(10, i);
		sum = a * temp + sum;
	}
	printf("%d", sum);
}