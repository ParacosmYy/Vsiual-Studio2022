#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct note
{
	char s[20];
	int  age;
	int  record;
};
int main()
{
	int number = 0;
	scanf("%d", &number);
	struct note d[5] ;
	for (int i = 0; i < number; i++)
	{
		scanf("%s", &d[i].s);
		scanf("%d%d", &d[i].age, &d[i].record);
	}
	for (int i = 0; i < number; i++)
	{
		if((double)(d[i].record * 1.2)>=(double)600.0000000000)
		{
			(d[i].record) = 600.0000/1.2;
		}
	}
	for (int i = 0; i < number; i++)
	{
		printf("%s ", d[i].s);
		printf("%d ", (d[i].age + 1));
		printf("%.0lf\n", (d[i].record*1.2));
	}
	return 0;
}