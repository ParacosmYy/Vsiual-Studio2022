#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	struct  student
	{
		char s[10];
		int chinese, math, english;
	};
	int number = 0;
	int max = 0;
	int count = 0;
	scanf("%d", &number);
	struct student stu[10000];
	for (int i = 0; i < number; i++)
	{
		scanf("%s", &stu[i].s);
		scanf("%d%d%d", &stu[i].chinese, &stu[i].math, &stu[i].english);
		if (max<(stu[i].chinese +stu[i].math+stu[i].english))
		{
			max = stu[i].chinese + stu[i].math + stu[i].english;
			count = i;
		}
	}
	printf("%s %d %d %d", stu[count].s, stu[count].chinese, stu[count].math, stu[count].english);
	return 0;
}