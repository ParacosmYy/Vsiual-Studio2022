#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char arr[] = { 0 };
	int chinese[] = { 0 };
	int math[] = { 0 };
	int english[] = { 0 };
	int number = 0;
	int max = 0;
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		scanf("%s%%d%d%d", arr[i], &chinese[i], &math[i], &english[i]);
	}
	for (int i = 0; i < number; i++)
	{   
		if (chinese[i]+math[i]+english[i]>max)
		{
			max = chinese[i] + math[i] + english[i];
			count=i;
		}
	}
	printf("%s %d %d %d", arr[count], chinese[count], math[count], english[count]);
	return 0;
}