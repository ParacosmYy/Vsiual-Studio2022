#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void bubble_sort(double num[], int n) //���Ҫ�����������飬Ҫ�������ĸ��� 
{
	int i, j, t; //i,jΪ����������tΪ��ʱ��������
	for (i = 0; i < n - 1; i++) //�����ڲ�ѭ������ 
	{
		//����ÿ��ѭ����С�ıȽϴ���
		for (j = 0; j < n - 1 - i; j++) //����-i����Ϊÿ��ð���ݳ������Ǹ���λ�ù̶��˲��ù� 
		{
			//�Ƚ����ڵ������� 
			if (num[j] > num[j + 1]) //�Ѵ����ð�ݵ����棬����С�������� 
			{
				//�ѵ�һ������ڶ���������λ�� 
				t = num[j + 1];
				num[j + 1] = num[j];
				num[j] = t;
			}
		}
	}
}

double average1(int arr[], int n,int m)//�齨ÿ��ѧ����ƽ���ɼ�����
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
	int average[10000] = { 0 };//����ÿ��ѧ��m���ƽ���ɼ�
	double all[10000] = { 0 };//����n��ѧ����ƽ���ɼ�
	int n = 0;//n��ѧ��
	int m = 0;//m����ʦ
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