#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int arr[1000][1000] ;
void fun(int a,int b,int c,int d)//(a��b)Ϊ�����Ͻǵ����꣬(c��d)Ϊ�����½ǵ�ͼ�ꡣ
 {
	int e = (a + c) / 2;
	int f = (b + d) / 2;
for (int i = a; i <= (a+c)/2; i++)
	{
		for (int  j = b; j <= (b+d)/2; j++)
		{
			arr[i][j] = 0;
		}
	}
if (a == (c-1)||b==d-1)
	{
		return;
	}
      fun((c + a + 1) / 2, b, c, (d + b - 1) / 2);//�����Ͻǵľ�����в�����
      fun(a, (d + b + 1) / 2, (c + a - 1) / 2, d);//�����½ǵľ�����в�����
      fun((c + a + 1) / 2, (d + b + 1) / 2, c, d);//�����½ǵľ�����в�����
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d", &n);
	k=pow(2, n);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			arr[i][j] = 1;
		}
	}
	fun(1, 1, k, k);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			printf("%d", arr[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	return 0;

}