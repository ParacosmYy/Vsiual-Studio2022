#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include<stdlib.h>
#include<math.h>
#include<string.h>
void changeover(char *arr, int start,int end)//×Ö·û´®ÄæÐò
{
	char temp;
	int i, j = 0;
	for (  i = start, j=end; i < j; i++ , j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void changeover_connect(char *arr,int number)//×óÒÆ×Ö·û´®ÄæÐò
{
	int len = strlen(arr);
	int position = number % len;
	changeover( arr, 0, position - 1);//ÄæÐòÇ°¶Ë
	changeover(arr, position, len - 1);//ÄæÐòºó¶Ë
	changeover(arr, 0, len - 1);//ÕûÌåÄæÐò

}

int main() 
{
	int n = 0;
	char arr1[100] = { 0 };
	gets_s(arr1);
	char arr2[100] = { 0 };
	gets_s(arr2);
	int sz = 0;
	sz = sizeof(arr1) / sizeof(arr1[0]);
	int str = 0;
	str = strlen(arr1);
	for (int i = 0; i < sz; i++)
	{
		int count = 0;
		changeover_connect(arr1, i);
		for (int j = 0; j < str; j++)
		{
			if(arr1[j]==arr2[j])
			{
				count++;
			}
		}
		if (count==str)
		{
			printf("1");
			break;
		}
	}
    return 0;
}