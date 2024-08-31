#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}

int main()
{
	int input = 0;
	int ret = 0;
	int x, y = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //转移表
	do
	{
		printf("***********************\n");
		printf("*********0.exit********\n");
		printf("*********1.add*********\n");
		printf("*********2.sub*********\n");
		printf("*********3.mul*********\n");
		printf("*********4.div*********\n");
		printf("***********************\n");
		printf("请选择您要进行的操作\n");
		scanf("%d", &input);
		if (input<=4&&input>=1)
		{
			printf("请输入您要操作的数字\n");
			scanf("%d%d", &x, &y);
			ret = (*p[input])(x, y);
			printf("ret = %d\n", ret);
		}
		else if(input==0)
		{
			printf("退出计算机\n");
		}
		else 
		{
			printf("输出有误，请重新输入\n");
		}
	} while (input);
	return 0;
}