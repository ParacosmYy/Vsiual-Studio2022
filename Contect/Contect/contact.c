#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
	printf("************************************\n");
	printf("*******1.add        2.sub    *******\n");
	printf("*******3.search     4.mod    *******\n");
	printf("*******5.show       6.sqrt   *******\n");
	printf("*******0.exit                 ******\n");
	printf("************************************\n");
}
int main()
{
	int input = 0;
	contact con;//通讯录
	initcontact(&con);//初始通讯录
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addcontact(&con);
			break;
		case 2:
			subcontact(&con);
			break;
		case 3:
			searchcontanct(&con);
			break;
		case 4:
			modifycontact(&con);
			break;
		case 5:
			showcontact(&con);
			break;
		case 6:
			sqrtcontact(&con);
			break;
		case 0:
			savecontact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入有误，请重新输入。\n");
			break;
		}
	} while (input);
	return 0;
}