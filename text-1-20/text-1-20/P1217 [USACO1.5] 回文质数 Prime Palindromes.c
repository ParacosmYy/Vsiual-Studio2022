#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int fun(int num)//回文数判断函数
{
	int a = 0;
	int b = 0;
	int c = num;
	while (num!=0)
	{
		a = num % 10;
		b = b * 10 + a;
		num = num / 10;
	}
	if (c == b)
	{
		return 1;
	}
	else
		return 0;
}
int prime(int n)//指数判断函数
{
	if (n == 2)
		return 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;

}
void swap(int a, int b)
{
	if (a>b)
	{
		b = a;
	}
}
int main()
{
	int number1, number2 = 0;
	scanf("%d%d", &number1,&number2);
	swap(number1, number2);
	for (int i = number1; i <= number2; i++)
	{
		if (fun(i) == 1 &&prime(i)==1)
			printf("%d\n", i);
	}
	return 0;
}