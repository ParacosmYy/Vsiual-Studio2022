#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

/*结构体*/
struct student
{
	long id;//学号
	char name[10];//姓名
	int age;//年龄
	float Chinese;//语文成绩
	float English;//英语成绩
	float Math;//数学成绩
	float sum;//总成绩
};

/*全局变量*/
struct student s[100];//学生信息数组
int count;//统计入库的学生数量

/*函数声明*/
void Menu();  //主菜单
void Addstudent();  //增添学生信息的函数
int Judge(int a, int b);  //a,b为阈值，Judge函数判断数字是否在阈值范围内
struct student id_Find();  //学号查询的函数，返回找到的学生信息数组
struct student name_Find();  //姓名查询的函数，返回找到的学生信息代码
void delete_student(int a);  //删除学生的函数
void WriteFile();  //写入文件的函数
void ReadFile();  //读入系统的函数
void change_score(int a);  //修改成绩的函数，a=1时通过学号修改，a=2时通过姓名修改
struct student Find();  //整合学号查询和姓名学习的函数
void change_id(int a);  //修改学号的函数
void change_name(int a);  //修改姓名的函数
void change_age(int a);  //修改年龄的函数
void output();  //输出全部信息的函数
void total_score();  //按总成绩排名

/*主函数*/
void main()
{
	int choice, choice1;
	int judge1;
	FILE* fp;
	printf("\n\n           *****欢迎使用学生成绩管理系统*****\n\n\n\n");
	//系统开始自动检索有无存档
	if ((fp = fopen("Database.txt", "rb")) == NULL)
		goto Start;  //若无存档，直接跳至主菜单
	else
	{
		printf("\n  检测到有存档，是否打开\n");  //若有存档，询问是否打开
		printf("\n                 1.打开存档        2.取消打开\n\n  请选择：");
		judge1 = Judge(1, 2);
		if (judge1 == 1)  //若打开，调用读取文件函数
			ReadFile();
		if (judge1 == 2)  //若不打开，跳至主菜单
			goto Start;
	}
Start:
	Menu();  //主菜单
	printf("\n  请选择您要使用的功能，输入序号并按回车：");
	choice = Judge(1, 5);  //choice的范围是[1,5]
	switch (choice)
	{
	case 1:  //增添信息
		printf("\n\n                   ***增添信息***\n\n\n");
	Start1_1:  //实现持续录入
		Addstudent();  //调用增添信息的函数
		printf("\n                 1.继续录入        2.返回主菜单\n\n  请选择：");
		judge1 = Judge(1, 2);
		if (judge1 == 1)
			goto Start1_1;
		if (judge1 == 2)
			goto Start;
		break;
	case 2:  //删除信息
		printf("\n\n                   ***删除信息***\n\n\n");
		printf("            1.按学号删除         2.按姓名删除\n\n\n");
		printf("  请输入您的选择：");
		choice = Judge(1, 2);
		switch (choice)
		{
		case 1:  //按学号删除
		Start2_1:  //实现持续按学号删除
			delete_student(1);
			printf("\n                 1.继续删除        2.返回主菜单\n\n  请选择：");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start2_1;
			if (judge1 == 2)
				goto Start;
			break;
		case 2:  //按姓名删除
		Start2_2:  //实现持续按姓名删除
			delete_student(2);
			printf("\n                 1.继续删除        2.返回主菜单\n\n  请选择：");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start2_2;
			if (judge1 == 2)
				goto Start;
			break;
		}

		break;
	case 3:  //修改信息
		printf("\n\n                   ***修改信息***\n\n\n");
		printf("            1.按学号修改         2.按姓名修改\n\n\n");
		printf("\n  请输入您的选择：");
		choice = Judge(1, 2);
		switch (choice)
		{
		case 1:  //case 1为按学号修改
			printf("\n\n                 1.修改学号        2.修改姓名\n\n");
			printf("\n\n                 3.修改年龄        4.修改成绩\n\n");
			printf("\n  请输入您的选择:");
			choice1 = Judge(1, 4);
			switch (choice1)
			{
			case 1:  //按学号修改学号
			Start3_1_1:
				change_id(1);
				printf("\n                 1.继续修改学号        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_1;
				if (judge1 == 2)
					goto Start;
				break;
			case 2:  //按学号修改姓名
			Start3_1_2:
				change_name(1);
				printf("\n                 1.继续修改姓名        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_2;
				if (judge1 == 2)
					goto Start;
				break;
			case 3:  //按学号修改年龄
			Start3_1_3:
				change_age(1);
				printf("\n                 1.继续修改年龄        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_3;
				if (judge1 == 2)
					goto Start;
				break;
			case 4:  //按学号修改成绩
			Start3_1_4:
				change_score(1);
				printf("\n                 1.继续修改成绩        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_4;
				if (judge1 == 2)
					goto Start;
				break;
			}
			break;
		case 2:  //按姓名修改
			printf("\n\n                 1.修改学号        2.修改姓名\n\n");
			printf("\n\n                 3.修改年龄        4.修改成绩\n\n");
			printf("\n  请输入您的选择:");
			choice1 = Judge(1, 4);
			switch (choice1)
			{
			case 1:  //按姓名修改学号
			Start3_2_1:
				change_id(2);
				printf("\n                 1.继续修改学号        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_1;
				if (judge1 == 2)
					goto Start;
				break;
			case 2:  //按姓名修改姓名
			Start3_2_2:
				change_name(2);
				printf("\n                 1.继续修改姓名        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_2;
				if (judge1 == 2)
					goto Start;
				break;
			case 3:  //按姓名修改年龄
			Start3_2_3:
				change_age(2);
				printf("\n                 1.继续修改年龄        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_3;
				if (judge1 == 2)
					goto Start;
				break;
			case 4:  //按姓名修改成绩
			Start3_2_4:
				change_score(2);
				printf("\n                 1.继续修改成绩        2.返回主菜单\n\n  请选择：");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_4;
				if (judge1 == 2)
					goto Start;
				break;
			}
			break;
		}
		break;
	case 4:  //查询信息
		printf("\n\n                   ***查询信息***\n\n\n");
		printf("            1.学号查询           2.姓名查询\n\n\n");
		printf("            3.输出全部信息       4.按总分从高到低排序\n\n\n");
		printf("            5.保存文档\n\n\n  请输入您的选择：");
		printf("  请输入您的选择：");
		choice = Judge(1, 4);
		switch (choice)
		{
		case 1:  //按学号查询
		Start4_1:
			id_Find();
			printf("\n                 1.继续查询        2.返回主菜单\n\n  请选择：");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start4_1;
			if (judge1 == 2)
				goto Start;
			break;
		case 2:  //按姓名查询
		Start4_2:
			name_Find();
			printf("\n                 1.继续查询        2.返回主菜单\n\n  请选择：");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start4_2;
			if (judge1 == 2)
				goto Start;
			break;
		case 3:  //输出全部信息
			output();
			printf("\n\n                       1.返回主菜单\n\n  请选择：");
			judge1 = Judge(1, 1);
			if (judge1 == 1)
				goto Start;
		case 4:  //按总成绩排名
			total_score();
			printf("\n\n                       1.返回主菜单\n\n  请选择：");
			judge1 = Judge(1, 1);
			if (judge1 == 1)
				goto Start;
		case 5:  //保存文件
			WriteFile();
			goto Start;
		}
		break;
	case 5:  //保存文件并退出
		WriteFile();
		printf("\n  已退出并保存系统，感谢您的使用！");
		break;
	}

}

/*函数定义*/
void Menu()  //主菜单
{
	printf("\n                        主菜单\n\n\n");
	printf("         1.增添信息              ");
	printf("         2.删除信息\n\n");
	printf("         3.修改信息              ");
	printf("         4.查询信息\n\n");
	printf("         5.保存并退出系统\n\n");
}

void Addstudent()  //增添信息
{
	long id;  //学号
	char name[10];  //姓名
	int age;  //年龄
	int i;
	float Chinese;  //语文成绩
	float English;  //英语成绩
	float Math;  //数学成绩
	printf("\n  请依次输入学生的学号、姓名、年龄和各科成绩，并按下回车键\n\n");
	printf("  请输入八位位学号：");
	scanf("%ld", &id);
again:
	while (id > 99999999 || id < 9999999)  //判断用户输入的学号是否为8位
	{
		printf("\n  输入错误,请输入正确的八位学号：");
		scanf("%ld", &id);
	}
	s[count].id = id;
	for (i = 0; i < count; i++)
	{
		if (s[i].id == s[count].id)  //当学号输入重复时，提醒用户重新输入
		{
			printf("\n  学号已存在,请重新输入：");
			scanf("%ld", &id);  //重新为id赋值
			s[count].id = id;
			goto again;
		}
		else
			s[count].id = id;
	}
	printf("  请输入姓名：");
	scanf("%s", name);
	strcpy(s[count].name, name);
	printf("  请输入年龄：");
	scanf("%d", &age);
	s[count].age = age;
	printf("  请输入语文成绩：");
	scanf("%f", &Chinese);
	s[count].Chinese = Chinese;
	printf("  请输入数学成绩：");
	scanf("%f", &Math);
	s[count].Math = Math;
	printf("  请输入英语成绩：");
	scanf("%f", &English);
	s[count].English = English;
	s[count].sum = s[count].Chinese + s[count].Math + s[count].English;  //计算出总分
	printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
	printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[count].id, s[count].name, s[count].age, s[count].Chinese, s[count].Math, s[count].English, s[count].sum);//该学生的全部信息
	printf("\n 录入成功！请继续操作。\n\n");  //提示录入成功
	count++;  //已入库学生数+1
	output();
}

int Judge(int a, int b)  //int a,int b为阈值，判断用户是否输入正确，如果用户输入的数值不在阈值内，提醒用户重新输入
{
	int judge;
	scanf("%d", &judge);  //函数自带输入功能，使用时变量=函数调用即可
	if (judge > b || judge < a)
		while (judge > b || judge < a)  //在阈值之外时提醒用户重新输入
		{
			printf("\n  输入错误，请重新输入：");
			scanf("%d", &judge);
		}
	else
		return judge;  //将用户输入的阈值内的正确值返回
}


struct student id_Find()    //按学号查询
{
	int i;
	long id;
	printf("\n  请输入学号：");
Again:
	scanf("%ld", &id);
	for (i = 0; i <= count; i++)  //用for循环对数组进行检索，将目标学号找到后，把整个数组中的信息输出出来
		if (s[i].id == id)
		{
			printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
			printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);//该学生的全部信息
			return s[i]; //将找到的数组返回
		}
	if (s[i].id != id)  //用户输入不存在的学号时提醒用户重新输入
	{
		printf("\n  未找到该学号,请重新输入：");
		goto Again;
	}
}



struct student name_Find()   //按姓名查找
{
	char name[10];
	int i;
	printf("\n  请输入姓名：");
Again:
	scanf("%s", name);
	for (i = 0; i <= count; i++)  //用for循环对数组进行检索，将目标学号找到后，把整个数组中的信息输出出来
	{
		if (strcmp(s[i].name, name) == 0)  //用strcmp函数判断字符串相等
		{
			printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
			printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);//该学生的全部信息
			return s[i];	//将找到的数组返回			
		}
	}
	if (strcmp(s[i].name, name) != 0)  //用户输入不存在的姓名时提醒用户重新输入
	{
		printf("\n  未找到该姓名，请重新输入：");
		goto Again;

	}
}


void delete_student(int a)  //删除学生信息的函数，a用来判断按学号/姓名删除
{
	int i, j;//中间变量
	int num;//中间变量
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("\n\n                 1.确认删除        2.取消删除\n\n  请选择：");
		num = Judge(1, 2);
		if (num == 1)//确认删除
		{
			for (j = i; j <= count; j++)
				s[j] = s[j + 1];  //将要删除的学生信息覆盖
			printf("\n  删除成功！ \n");
			count--;//学生总数减一
			return;
		}
		else if (num == 2)//取消删除
		{
			printf("\n  已取消删除！ \n");
			return;
		}
	}
}


void change_score(int a)  //修改成绩的函数，a用来判断按学号/姓名修改
{
	int i, choice;
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("\n\n        1.语文        2.数学        3.英语\n");
		printf("\n  请输入您想修改的科目:");
		choice = Judge(1, 3);
		printf("\n  请输入修改后的分数：");
		//根据用户的选择，将不同科目的分数重新赋值
		if (choice == 1)
			scanf("%f", &s[i].Chinese);
		else if (choice == 2)
			scanf("%f", &s[i].Math);
		else if (choice == 3)
			scanf("%f", &s[i].English);
		s[i].sum = s[i].Chinese + s[i].Math + s[i].English;  //重新计算学生的总成绩
		printf("\n  修改成功!");
		printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
		return;  //结束函数
	}
}


void change_name(int a)  //修改姓名的函数，a用来判断按学号/姓名修改
{
	int i;
	char name[10];
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("\n  请输入修改后的姓名：");
		scanf("%s", name);
		strcpy(s[i].name, name);  //将姓名重新赋值
		printf("\n  修改成功!");
		printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
		return;  //结束函数
	}
}


void change_id(int a)  //修改学号的函数，a用来判断按学号/姓名修改
{
	int i;
	long id;
	int num;
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("  请输入修改后的八位位学号：");

		scanf("%ld", &id);
	again:
		while (id > 99999999 || id < 9999999)  //判断用户输入的学号是否为八位
		{
			printf("\n  输入错误,请输入正确的八位学号：");
			scanf("%ld", &id);
		}
		s[i].id = id;

		for (num = 0; num < i; num++)  //判断i之前是否有相同的学号
		{
			if (s[i].id == s[num].id)	  //当学号输入重复时，提醒用户重新输入
			{
				printf("\n  学号已存在,请重新输入：");
				scanf("%ld", &id);
				s[i].id = id;
				goto again;  //保证用户重新输入的学号为八位，并重新判断是否已经存在
			}
			else
				s[i].id = id;
		}
		for (num = i + 1; num <= count; num++)  //判断i之后是否有相同的学号
		{
			if (s[i].id == s[num].id)	  //当学号输入重复时，提醒用户重新输入
			{
				printf("\n  学号已存在,请重新输入：");
				scanf("%ld", &id);
				s[i].id = id;
				goto again;  //保证用户重新输入的学号为八位，并重新判断是否已经存在
			}
			else
				s[i].id = id;
		}

		printf("\n  修改成功!");
		printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
		return;
	}
}

void change_age(int a)  //修改年龄的函数，a用来判断按学号/姓名删除
{
	int i;
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);  //把函数返回的值赋值给s[i]
		printf("\n  请输入修改后的年龄：");
		scanf("%d", s[i].age);  //将年龄重新赋值
		printf("\n  修改成功!");
		printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");//打印一遍该学生的所有信息
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);//该学生的全部信息
		return;
	}
}



struct student Find(int a)  //将按学号查找和按姓名查找两个功能整合到一起
{
	int i;
	for (i = 0; i <= count; i++)
	{
		if (a == 1)
		{
			s[i] = id_Find();  //如果a=1时，将调用按学号查找的函数
			return s[i];  //返回按学号查找到的数组
		}
		else if (a == 2)
		{
			s[i] = name_Find();  //如果a=2时，将调用按姓名查找的函数
			return s[i];  //返回按姓名查找的数组
		}
	}
}



void output()  //输出全部学生信息的函数
{
	int i;
	printf("\n\n  \t学号\t姓名\t年龄\t语文\t数学\t英语\t总分\n");  //显示顶部文字信息
	for (i = 0; i < count; i++)  //通过for循环把数组中的每条信息输出在文字信息的下方
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
	return;
}


void total_score()   //按总分排名从高到底排序的函数
{
	int i, j;  //外层循环的参数，内层循环的参数
	struct student m;  //定义一个用来替换数组的中间变量
	for (i = 0; i <= count; i++)
		for (j = i + 1; j <= count + 1; j++)  //j=i+1获取s[i]后面的元素s[j]
			if (s[j].sum > s[i].sum)  //通过总分的比较，用赋值的方法调换数组中信息的顺序
			{
				m = s[i];
				s[i] = s[j];
				s[j] = m;
			}
	output();  //最后将所有的信息输出
	return;
}



void WriteFile()  //写入文件
{
	FILE* fp;
	int i;
	if ((fp = fopen("Database.txt", "wb")) == NULL)  //以二进制写方式打开文件
	{
		printf("\n  不能打开文件!\n");
		return;
	}
	if (fwrite(&count, sizeof(int), 1, fp) != 1)
	{
		printf("\n  写入文件错误!\n");
	}
	for (i = 0; i < count; i++)
	{
		if (fwrite(&s[i], sizeof(struct student), 1, fp) != 1)
		{
			printf("\n  写入文件错误!\n");
		}
	}
	printf("\n  保存成功!\n");
	fclose(fp);
	output();  //将保存的信息全部输出，方便用户查看
}


void ReadFile()  //读取文件
{
	FILE* fp;
	int i;
	if ((fp = fopen("Database.txt", "rb")) == NULL)  //以以二进制读的方式打开文件
	{
		printf("\n  不能打开文件!\n");
		return;
	}
	if (fread(&count, sizeof(int), 1, fp) != 1)
	{
		count = -1;
	}
	else
	{
		for (i = 0; i < count; i++)
		{
			fread(&s[i], sizeof(struct student), 1, fp);
		}
		printf("\n  读取成功\n\n");
		output();  //输出读取到的全部信息，方便用户查看
	}
	fclose(fp);
}