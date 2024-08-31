#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int arr[1000][1000] ;
void fun(int a,int b,int c,int d)//(a，b)为最左上角的坐标，(c，d)为最右下角的图标。
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
      fun((c + a + 1) / 2, b, c, (d + b - 1) / 2);//对右上角的矩阵进行操作；
      fun(a, (d + b + 1) / 2, (c + a - 1) / 2, d);//对左下角的矩阵进行操作；
      fun((c + a + 1) / 2, (d + b + 1) / 2, c, d);//对右下角的矩阵进行操作；
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