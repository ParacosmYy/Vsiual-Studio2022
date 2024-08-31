#include"contact.h"
//��̬�汾
//void initcontact(contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->count));
//}

//��̬�汾
int initcontact(contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date=(peoinfo*)calloc(inc_max,sizeof(peoinfo));
	if (pc->date==NULL)
	{
		printf("initcontact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = inc_max;
	loadcontact(pc);
	return 0;
}
void destroycontact(contact* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
	pc = NULL;
}
//��̬�汾
//void addcontact(contact* pc)
//{
//	assert(pc);
//	if (pc->count==100)
//	{
//		printf("ͨѶ¼�Ѿ�����\n");
//	}
//	printf("��������ϵ������\n");
//	scanf("%s", pc->date[pc->count].name);
//	printf("��������ϵ������\n");
//	scanf("%d", &pc->date[pc->count].age);
//	printf("��������ϵ���Ա�\n");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("��������ϵ�˵绰\n");
//	scanf("%s", pc->date[pc->count].tele);
//	printf("��������ϵ�˵�ַ\n");
//	scanf("%s", pc->date[pc->count].addr);
//	
//	pc->count++;
//	printf("���ӳɹ�\n");
//}

checkcapacity(contact* pc){
	if (pc->capacity == pc->count)
	{
		peoinfo* ptr = (peoinfo*)realloc(pc->date, ((pc->capacity) + in_max) * sizeof(peoinfo));
		if (ptr == NULL)
		{
			printf("addcontact::%s\n", strerror(errno));
			return;
		}
		else
		{


			pc->date = ptr;
			pc->capacity += in_max;
			printf("���ݳɹ���");
		}
	}
}

//��̬�汾
void addcontact(contact* pc)
{
	assert(pc);
	//����
	checkcapacity(pc);
	
	printf("��������ϵ������\n");
	scanf("%s", pc->date[pc->count].name);
	printf("��������ϵ������\n");
	scanf("%d", &pc->date[pc->count].age);
	printf("��������ϵ���Ա�\n");
	scanf("%s", pc->date[pc->count].sex);
	printf("��������ϵ�˵绰\n");
	scanf("%s", pc->date[pc->count].tele);
	printf("��������ϵ�˵�ַ\n");
	scanf("%s", pc->date[pc->count].addr);

	pc->count++;
	printf("���ӳɹ�\n");
}


void showcontact(const contact* pc)
{
	assert(pc);
	printf("%30s\t%5s\t%10s\t%20s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%30s\t5%d\t%10s\t%20s\t%30s\n",
			pc->date[i].name,
			pc->date[i].age,
			pc->date[i].sex,
			pc->date[i].tele,
			pc->date[i].addr);
	}
}
int find(contact* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->date[i].name, name))
		{
			return i;//�����±�
		}
	}return -1;
}

void subcontact(contact* pc)
{
	char name[name_max] = { 0 };
	assert(pc);
	if (pc->count==0)
	{
		printf("ͨѶ¼�ǿյ�\n");
		return;
	}
	printf("������Ҫɾ������ϵ������\n");
	scanf("%s", name);
	int ret = 0;
	//1. ����
	ret = find( pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2. ɾ��
	for (int i =ret; i < pc->count-1; i++)//��ÿ��Ԫ�ض���ǰ����һλ��Ȼ��count-- Ŀ��Ϊ��������ret�±��Ԫ����ʧ��
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}

void searchcontanct(contact* pc)
{
	assert(pc);
	char name[name_max] = { 0 };
	int ret = 0;
	printf("�����Ҫ�������˵���");
	//1. ����
	ret = find(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�������˲�����\n");
		return;
	}
	//2.��ӡ
	printf("%30s\t%5s\t%10s\t%20s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%30s\t5%d\t%10s\t%20s\t%30s\n",
			pc->date[ret].name,
			pc->date[ret].age,
			pc->date[ret].sex,
			pc->date[ret].tele,
			pc->date[ret].addr);
}
void modifycontact(contact* pc)
{
	assert(pc);
	char name[name_max] = { 0 };
	int ret = 0;
	printf("�����Ҫ�޸ĵ��˵���\n");
	//1. ����
	ret = find(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("�Ѿ���ѯ��Ҫ�޸ĵ��ˣ���������ʼ�����޸�");
	//2.�޸�
	printf("��������ϵ������\n");
	scanf("%s", pc->date[ret].name);
	printf("��������ϵ������\n");
	scanf("%d", &pc->date[ret].age);
	printf("��������ϵ���Ա�\n");
	scanf("%s", pc->date[ret].sex);
	printf("��������ϵ�˵绰\n");
	scanf("%s", pc->date[ret].tele);
	printf("��������ϵ�˵�ַ\n");
	scanf("%s", pc->date[ret].addr);
	printf("�޸ĳɹ�");
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((peoinfo*)e1)->name , ((peoinfo*)e2)->name);
}

void sqrtcontact(contact* pc)
{
	assert(pc);
	qsort(pc->date, pc->count, sizeof(peoinfo), cmp_name);
	printf("����ɹ�\n");
}

void savecontact(contact* pc)
{
	//�����ļ�
	assert(pc);
	FILE* pf = fopen("contact.txt", "wb");
	if (pf==NULL)
	{
		perror("savecontact");
		return 1;
	}
	//д�ļ�
	for (int i = 0; i < pc->count; i++)
	{
		fwrite(pc->date+i, sizeof(peoinfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

void loadcontact(contact* pc)
{
	//���ļ�
	assert(pc);
	FILE* pf_read = fopen("contact.txt", "rb");
	if (pf_read==NULL)
	{
		perror(loadcontact); 
		return 1;
	}
	//��ȡ�ļ�
	peoinfo tep = { 0 };//������ʱ���� ��ֹͨѶ¼��ռ䲻�����޷��洢
	while (fread(&tep,sizeof(peoinfo),1,pf_read)==1)
	{
		checkcapacity(pc);

		pc->date[pc->count] = tep;
		pc->count++;
	}
	fclose(pf_read);
	pf_read = NULL;
}