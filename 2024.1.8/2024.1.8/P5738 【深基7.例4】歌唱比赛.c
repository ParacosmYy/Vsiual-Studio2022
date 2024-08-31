#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void bubble_sort(double num[], int n) //存放要排序数的数组，要排序数的个数 
{
	int i, j, t; //i,j为遍历变量，t为临时交换变量
	for (i = 0; i < n - 1; i++) //控制内层循环次数 
	{
		//控制每次循环最小的比较次数
		for (j = 0; j < n - 1 - i; j++) //这里-i是因为每次冒完泡出来的那个数位置固定了不用管 
		{
			//比较相邻的两个数 
			if (num[j] > num[j + 1]) //把大的数冒泡到后面，即从小到大排序 
			{
				//把第一个数与第二个数交换位置 
				t = num[j + 1];
				num[j + 1] = num[j];
				num[j] = t;
			}
		}
	}
}

double average1(int arr[], int n,int m)//组建每个学生的平均成绩函数
{
	bubble_sort( arr, m);
	int a = 0;
	for (int i = 0; i < m; i++)
	{
		a = a + arr[i];
	}
	a = a - arr[0] - arr[m - 1];
	a = a / (n - 2);
	return a;
}
int main()
{
	int average[10000] = { 0 };//放入每个学生m项的平均成绩
	double all[10000] = { 0 };//放入n个学生的平均成绩
	int n = 0;//n个学生
	int m = 0;//m个老师
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", & average[j]);
		}
		all[i] = average1(average, n,m);
	}
	bubble_sort(all, n);
	printf("%.2lf", all[n - 1]);
	return 0;
}