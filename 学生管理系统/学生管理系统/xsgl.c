#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

/*�ṹ��*/
struct student
{
	long id;//ѧ��
	char name[10];//����
	int age;//����
	float Chinese;//���ĳɼ�
	float English;//Ӣ��ɼ�
	float Math;//��ѧ�ɼ�
	float sum;//�ܳɼ�
};

/*ȫ�ֱ���*/
struct student s[100];//ѧ����Ϣ����
int count;//ͳ������ѧ������

/*��������*/
void Menu();  //���˵�
void Addstudent();  //����ѧ����Ϣ�ĺ���
int Judge(int a, int b);  //a,bΪ��ֵ��Judge�����ж������Ƿ�����ֵ��Χ��
struct student id_Find();  //ѧ�Ų�ѯ�ĺ����������ҵ���ѧ����Ϣ����
struct student name_Find();  //������ѯ�ĺ����������ҵ���ѧ����Ϣ����
void delete_student(int a);  //ɾ��ѧ���ĺ���
void WriteFile();  //д���ļ��ĺ���
void ReadFile();  //����ϵͳ�ĺ���
void change_score(int a);  //�޸ĳɼ��ĺ�����a=1ʱͨ��ѧ���޸ģ�a=2ʱͨ�������޸�
struct student Find();  //����ѧ�Ų�ѯ������ѧϰ�ĺ���
void change_id(int a);  //�޸�ѧ�ŵĺ���
void change_name(int a);  //�޸������ĺ���
void change_age(int a);  //�޸�����ĺ���
void output();  //���ȫ����Ϣ�ĺ���
void total_score();  //���ܳɼ�����

/*������*/
void main()
{
	int choice, choice1;
	int judge1;
	FILE* fp;
	printf("\n\n           *****��ӭʹ��ѧ���ɼ�����ϵͳ*****\n\n\n\n");
	//ϵͳ��ʼ�Զ��������޴浵
	if ((fp = fopen("Database.txt", "rb")) == NULL)
		goto Start;  //���޴浵��ֱ���������˵�
	else
	{
		printf("\n  ��⵽�д浵���Ƿ��\n");  //���д浵��ѯ���Ƿ��
		printf("\n                 1.�򿪴浵        2.ȡ����\n\n  ��ѡ��");
		judge1 = Judge(1, 2);
		if (judge1 == 1)  //���򿪣����ö�ȡ�ļ�����
			ReadFile();
		if (judge1 == 2)  //�����򿪣��������˵�
			goto Start;
	}
Start:
	Menu();  //���˵�
	printf("\n  ��ѡ����Ҫʹ�õĹ��ܣ�������Ų����س���");
	choice = Judge(1, 5);  //choice�ķ�Χ��[1,5]
	switch (choice)
	{
	case 1:  //������Ϣ
		printf("\n\n                   ***������Ϣ***\n\n\n");
	Start1_1:  //ʵ�ֳ���¼��
		Addstudent();  //����������Ϣ�ĺ���
		printf("\n                 1.����¼��        2.�������˵�\n\n  ��ѡ��");
		judge1 = Judge(1, 2);
		if (judge1 == 1)
			goto Start1_1;
		if (judge1 == 2)
			goto Start;
		break;
	case 2:  //ɾ����Ϣ
		printf("\n\n                   ***ɾ����Ϣ***\n\n\n");
		printf("            1.��ѧ��ɾ��         2.������ɾ��\n\n\n");
		printf("  ����������ѡ��");
		choice = Judge(1, 2);
		switch (choice)
		{
		case 1:  //��ѧ��ɾ��
		Start2_1:  //ʵ�ֳ�����ѧ��ɾ��
			delete_student(1);
			printf("\n                 1.����ɾ��        2.�������˵�\n\n  ��ѡ��");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start2_1;
			if (judge1 == 2)
				goto Start;
			break;
		case 2:  //������ɾ��
		Start2_2:  //ʵ�ֳ���������ɾ��
			delete_student(2);
			printf("\n                 1.����ɾ��        2.�������˵�\n\n  ��ѡ��");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start2_2;
			if (judge1 == 2)
				goto Start;
			break;
		}

		break;
	case 3:  //�޸���Ϣ
		printf("\n\n                   ***�޸���Ϣ***\n\n\n");
		printf("            1.��ѧ���޸�         2.�������޸�\n\n\n");
		printf("\n  ����������ѡ��");
		choice = Judge(1, 2);
		switch (choice)
		{
		case 1:  //case 1Ϊ��ѧ���޸�
			printf("\n\n                 1.�޸�ѧ��        2.�޸�����\n\n");
			printf("\n\n                 3.�޸�����        4.�޸ĳɼ�\n\n");
			printf("\n  ����������ѡ��:");
			choice1 = Judge(1, 4);
			switch (choice1)
			{
			case 1:  //��ѧ���޸�ѧ��
			Start3_1_1:
				change_id(1);
				printf("\n                 1.�����޸�ѧ��        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_1;
				if (judge1 == 2)
					goto Start;
				break;
			case 2:  //��ѧ���޸�����
			Start3_1_2:
				change_name(1);
				printf("\n                 1.�����޸�����        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_2;
				if (judge1 == 2)
					goto Start;
				break;
			case 3:  //��ѧ���޸�����
			Start3_1_3:
				change_age(1);
				printf("\n                 1.�����޸�����        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_3;
				if (judge1 == 2)
					goto Start;
				break;
			case 4:  //��ѧ���޸ĳɼ�
			Start3_1_4:
				change_score(1);
				printf("\n                 1.�����޸ĳɼ�        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_1_4;
				if (judge1 == 2)
					goto Start;
				break;
			}
			break;
		case 2:  //�������޸�
			printf("\n\n                 1.�޸�ѧ��        2.�޸�����\n\n");
			printf("\n\n                 3.�޸�����        4.�޸ĳɼ�\n\n");
			printf("\n  ����������ѡ��:");
			choice1 = Judge(1, 4);
			switch (choice1)
			{
			case 1:  //�������޸�ѧ��
			Start3_2_1:
				change_id(2);
				printf("\n                 1.�����޸�ѧ��        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_1;
				if (judge1 == 2)
					goto Start;
				break;
			case 2:  //�������޸�����
			Start3_2_2:
				change_name(2);
				printf("\n                 1.�����޸�����        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_2;
				if (judge1 == 2)
					goto Start;
				break;
			case 3:  //�������޸�����
			Start3_2_3:
				change_age(2);
				printf("\n                 1.�����޸�����        2.�������˵�\n\n  ��ѡ��");
				judge1 = Judge(1, 2);
				if (judge1 == 1)
					goto Start3_2_3;
				if (judge1 == 2)
					goto Start;
				break;
			case 4:  //�������޸ĳɼ�
			Start3_2_4:
				change_score(2);
				printf("\n                 1.�����޸ĳɼ�        2.�������˵�\n\n  ��ѡ��");
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
	case 4:  //��ѯ��Ϣ
		printf("\n\n                   ***��ѯ��Ϣ***\n\n\n");
		printf("            1.ѧ�Ų�ѯ           2.������ѯ\n\n\n");
		printf("            3.���ȫ����Ϣ       4.���ִܷӸߵ�������\n\n\n");
		printf("            5.�����ĵ�\n\n\n  ����������ѡ��");
		printf("  ����������ѡ��");
		choice = Judge(1, 4);
		switch (choice)
		{
		case 1:  //��ѧ�Ų�ѯ
		Start4_1:
			id_Find();
			printf("\n                 1.������ѯ        2.�������˵�\n\n  ��ѡ��");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start4_1;
			if (judge1 == 2)
				goto Start;
			break;
		case 2:  //��������ѯ
		Start4_2:
			name_Find();
			printf("\n                 1.������ѯ        2.�������˵�\n\n  ��ѡ��");
			judge1 = Judge(1, 2);
			if (judge1 == 1)
				goto Start4_2;
			if (judge1 == 2)
				goto Start;
			break;
		case 3:  //���ȫ����Ϣ
			output();
			printf("\n\n                       1.�������˵�\n\n  ��ѡ��");
			judge1 = Judge(1, 1);
			if (judge1 == 1)
				goto Start;
		case 4:  //���ܳɼ�����
			total_score();
			printf("\n\n                       1.�������˵�\n\n  ��ѡ��");
			judge1 = Judge(1, 1);
			if (judge1 == 1)
				goto Start;
		case 5:  //�����ļ�
			WriteFile();
			goto Start;
		}
		break;
	case 5:  //�����ļ����˳�
		WriteFile();
		printf("\n  ���˳�������ϵͳ����л����ʹ�ã�");
		break;
	}

}

/*��������*/
void Menu()  //���˵�
{
	printf("\n                        ���˵�\n\n\n");
	printf("         1.������Ϣ              ");
	printf("         2.ɾ����Ϣ\n\n");
	printf("         3.�޸���Ϣ              ");
	printf("         4.��ѯ��Ϣ\n\n");
	printf("         5.���沢�˳�ϵͳ\n\n");
}

void Addstudent()  //������Ϣ
{
	long id;  //ѧ��
	char name[10];  //����
	int age;  //����
	int i;
	float Chinese;  //���ĳɼ�
	float English;  //Ӣ��ɼ�
	float Math;  //��ѧ�ɼ�
	printf("\n  ����������ѧ����ѧ�š�����������͸��Ƴɼ��������»س���\n\n");
	printf("  �������λλѧ�ţ�");
	scanf("%ld", &id);
again:
	while (id > 99999999 || id < 9999999)  //�ж��û������ѧ���Ƿ�Ϊ8λ
	{
		printf("\n  �������,��������ȷ�İ�λѧ�ţ�");
		scanf("%ld", &id);
	}
	s[count].id = id;
	for (i = 0; i < count; i++)
	{
		if (s[i].id == s[count].id)  //��ѧ�������ظ�ʱ�������û���������
		{
			printf("\n  ѧ���Ѵ���,���������룺");
			scanf("%ld", &id);  //����Ϊid��ֵ
			s[count].id = id;
			goto again;
		}
		else
			s[count].id = id;
	}
	printf("  ������������");
	scanf("%s", name);
	strcpy(s[count].name, name);
	printf("  ���������䣺");
	scanf("%d", &age);
	s[count].age = age;
	printf("  ���������ĳɼ���");
	scanf("%f", &Chinese);
	s[count].Chinese = Chinese;
	printf("  ��������ѧ�ɼ���");
	scanf("%f", &Math);
	s[count].Math = Math;
	printf("  ������Ӣ��ɼ���");
	scanf("%f", &English);
	s[count].English = English;
	s[count].sum = s[count].Chinese + s[count].Math + s[count].English;  //������ܷ�
	printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
	printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[count].id, s[count].name, s[count].age, s[count].Chinese, s[count].Math, s[count].English, s[count].sum);//��ѧ����ȫ����Ϣ
	printf("\n ¼��ɹ��������������\n\n");  //��ʾ¼��ɹ�
	count++;  //�����ѧ����+1
	output();
}

int Judge(int a, int b)  //int a,int bΪ��ֵ���ж��û��Ƿ�������ȷ������û��������ֵ������ֵ�ڣ������û���������
{
	int judge;
	scanf("%d", &judge);  //�����Դ����빦�ܣ�ʹ��ʱ����=�������ü���
	if (judge > b || judge < a)
		while (judge > b || judge < a)  //����ֵ֮��ʱ�����û���������
		{
			printf("\n  ����������������룺");
			scanf("%d", &judge);
		}
	else
		return judge;  //���û��������ֵ�ڵ���ȷֵ����
}


struct student id_Find()    //��ѧ�Ų�ѯ
{
	int i;
	long id;
	printf("\n  ������ѧ�ţ�");
Again:
	scanf("%ld", &id);
	for (i = 0; i <= count; i++)  //��forѭ����������м�������Ŀ��ѧ���ҵ��󣬰����������е���Ϣ�������
		if (s[i].id == id)
		{
			printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
			printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);//��ѧ����ȫ����Ϣ
			return s[i]; //���ҵ������鷵��
		}
	if (s[i].id != id)  //�û����벻���ڵ�ѧ��ʱ�����û���������
	{
		printf("\n  δ�ҵ���ѧ��,���������룺");
		goto Again;
	}
}



struct student name_Find()   //����������
{
	char name[10];
	int i;
	printf("\n  ������������");
Again:
	scanf("%s", name);
	for (i = 0; i <= count; i++)  //��forѭ����������м�������Ŀ��ѧ���ҵ��󣬰����������е���Ϣ�������
	{
		if (strcmp(s[i].name, name) == 0)  //��strcmp�����ж��ַ������
		{
			printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
			printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);//��ѧ����ȫ����Ϣ
			return s[i];	//���ҵ������鷵��			
		}
	}
	if (strcmp(s[i].name, name) != 0)  //�û����벻���ڵ�����ʱ�����û���������
	{
		printf("\n  δ�ҵ������������������룺");
		goto Again;

	}
}


void delete_student(int a)  //ɾ��ѧ����Ϣ�ĺ�����a�����жϰ�ѧ��/����ɾ��
{
	int i, j;//�м����
	int num;//�м����
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("\n\n                 1.ȷ��ɾ��        2.ȡ��ɾ��\n\n  ��ѡ��");
		num = Judge(1, 2);
		if (num == 1)//ȷ��ɾ��
		{
			for (j = i; j <= count; j++)
				s[j] = s[j + 1];  //��Ҫɾ����ѧ����Ϣ����
			printf("\n  ɾ���ɹ��� \n");
			count--;//ѧ��������һ
			return;
		}
		else if (num == 2)//ȡ��ɾ��
		{
			printf("\n  ��ȡ��ɾ���� \n");
			return;
		}
	}
}


void change_score(int a)  //�޸ĳɼ��ĺ�����a�����жϰ�ѧ��/�����޸�
{
	int i, choice;
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("\n\n        1.����        2.��ѧ        3.Ӣ��\n");
		printf("\n  �����������޸ĵĿ�Ŀ:");
		choice = Judge(1, 3);
		printf("\n  �������޸ĺ�ķ�����");
		//�����û���ѡ�񣬽���ͬ��Ŀ�ķ������¸�ֵ
		if (choice == 1)
			scanf("%f", &s[i].Chinese);
		else if (choice == 2)
			scanf("%f", &s[i].Math);
		else if (choice == 3)
			scanf("%f", &s[i].English);
		s[i].sum = s[i].Chinese + s[i].Math + s[i].English;  //���¼���ѧ�����ܳɼ�
		printf("\n  �޸ĳɹ�!");
		printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
		return;  //��������
	}
}


void change_name(int a)  //�޸������ĺ�����a�����жϰ�ѧ��/�����޸�
{
	int i;
	char name[10];
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("\n  �������޸ĺ��������");
		scanf("%s", name);
		strcpy(s[i].name, name);  //���������¸�ֵ
		printf("\n  �޸ĳɹ�!");
		printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
		return;  //��������
	}
}


void change_id(int a)  //�޸�ѧ�ŵĺ�����a�����жϰ�ѧ��/�����޸�
{
	int i;
	long id;
	int num;
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);
		printf("  �������޸ĺ�İ�λλѧ�ţ�");

		scanf("%ld", &id);
	again:
		while (id > 99999999 || id < 9999999)  //�ж��û������ѧ���Ƿ�Ϊ��λ
		{
			printf("\n  �������,��������ȷ�İ�λѧ�ţ�");
			scanf("%ld", &id);
		}
		s[i].id = id;

		for (num = 0; num < i; num++)  //�ж�i֮ǰ�Ƿ�����ͬ��ѧ��
		{
			if (s[i].id == s[num].id)	  //��ѧ�������ظ�ʱ�������û���������
			{
				printf("\n  ѧ���Ѵ���,���������룺");
				scanf("%ld", &id);
				s[i].id = id;
				goto again;  //��֤�û����������ѧ��Ϊ��λ���������ж��Ƿ��Ѿ�����
			}
			else
				s[i].id = id;
		}
		for (num = i + 1; num <= count; num++)  //�ж�i֮���Ƿ�����ͬ��ѧ��
		{
			if (s[i].id == s[num].id)	  //��ѧ�������ظ�ʱ�������û���������
			{
				printf("\n  ѧ���Ѵ���,���������룺");
				scanf("%ld", &id);
				s[i].id = id;
				goto again;  //��֤�û����������ѧ��Ϊ��λ���������ж��Ƿ��Ѿ�����
			}
			else
				s[i].id = id;
		}

		printf("\n  �޸ĳɹ�!");
		printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
		return;
	}
}

void change_age(int a)  //�޸�����ĺ�����a�����жϰ�ѧ��/����ɾ��
{
	int i;
	for (i = 0; i <= count; i++)
	{
		s[i] = Find(a);  //�Ѻ������ص�ֵ��ֵ��s[i]
		printf("\n  �������޸ĺ�����䣺");
		scanf("%d", s[i].age);  //���������¸�ֵ
		printf("\n  �޸ĳɹ�!");
		printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");//��ӡһ���ѧ����������Ϣ
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);//��ѧ����ȫ����Ϣ
		return;
	}
}



struct student Find(int a)  //����ѧ�Ų��ҺͰ��������������������ϵ�һ��
{
	int i;
	for (i = 0; i <= count; i++)
	{
		if (a == 1)
		{
			s[i] = id_Find();  //���a=1ʱ�������ð�ѧ�Ų��ҵĺ���
			return s[i];  //���ذ�ѧ�Ų��ҵ�������
		}
		else if (a == 2)
		{
			s[i] = name_Find();  //���a=2ʱ�������ð��������ҵĺ���
			return s[i];  //���ذ��������ҵ�����
		}
	}
}



void output()  //���ȫ��ѧ����Ϣ�ĺ���
{
	int i;
	printf("\n\n  \tѧ��\t����\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");  //��ʾ����������Ϣ
	for (i = 0; i < count; i++)  //ͨ��forѭ���������е�ÿ����Ϣ�����������Ϣ���·�
		printf("  %8ld\t%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", s[i].id, s[i].name, s[i].age, s[i].Chinese, s[i].Math, s[i].English, s[i].sum);
	return;
}


void total_score()   //���ܷ������Ӹߵ�������ĺ���
{
	int i, j;  //���ѭ���Ĳ������ڲ�ѭ���Ĳ���
	struct student m;  //����һ�������滻������м����
	for (i = 0; i <= count; i++)
		for (j = i + 1; j <= count + 1; j++)  //j=i+1��ȡs[i]�����Ԫ��s[j]
			if (s[j].sum > s[i].sum)  //ͨ���ֵܷıȽϣ��ø�ֵ�ķ���������������Ϣ��˳��
			{
				m = s[i];
				s[i] = s[j];
				s[j] = m;
			}
	output();  //������е���Ϣ���
	return;
}



void WriteFile()  //д���ļ�
{
	FILE* fp;
	int i;
	if ((fp = fopen("Database.txt", "wb")) == NULL)  //�Զ�����д��ʽ���ļ�
	{
		printf("\n  ���ܴ��ļ�!\n");
		return;
	}
	if (fwrite(&count, sizeof(int), 1, fp) != 1)
	{
		printf("\n  д���ļ�����!\n");
	}
	for (i = 0; i < count; i++)
	{
		if (fwrite(&s[i], sizeof(struct student), 1, fp) != 1)
		{
			printf("\n  д���ļ�����!\n");
		}
	}
	printf("\n  ����ɹ�!\n");
	fclose(fp);
	output();  //���������Ϣȫ������������û��鿴
}


void ReadFile()  //��ȡ�ļ�
{
	FILE* fp;
	int i;
	if ((fp = fopen("Database.txt", "rb")) == NULL)  //���Զ����ƶ��ķ�ʽ���ļ�
	{
		printf("\n  ���ܴ��ļ�!\n");
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
		printf("\n  ��ȡ�ɹ�\n\n");
		output();  //�����ȡ����ȫ����Ϣ�������û��鿴
	}
	fclose(fp);
}