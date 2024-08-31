#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	int temp = 0,temp1=0,temp2=0;
	int arr[] = { 0 };
	char arr1[] = { 0 };
	scanf("%d%d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &arr[i]);
		scanf("%s", &arr1[i]);
	}
	for (int j = 0; j < b; j++)
	{

		scanf("%d", &temp);
		scanf("%d", &temp1);
		if (temp == 0)
		{
			temp2 = temp2 + temp1;
		}
		else if (temp == 1)
		{
			temp2 = temp2 - temp1;
		}
	}
	printf("%s", arr1[temp2]);
	return 0;
}