#include"contact.h"
//静态版本
//void initcontact(contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->count));
//}

//动态版本
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
//静态版本
//void addcontact(contact* pc)
//{
//	assert(pc);
//	if (pc->count==100)
//	{
//		printf("通讯录已经填满\n");
//	}
//	printf("请输入联系人姓名\n");
//	scanf("%s", pc->date[pc->count].name);
//	printf("请输入联系人年龄\n");
//	scanf("%d", &pc->date[pc->count].age);
//	printf("请输入联系人性别\n");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("请输入联系人电话\n");
//	scanf("%s", pc->date[pc->count].tele);
//	printf("请输入联系人地址\n");
//	scanf("%s", pc->date[pc->count].addr);
//	
//	pc->count++;
//	printf("增加成功\n");
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
			printf("增容成功！");
		}
	}
}

//动态版本
void addcontact(contact* pc)
{
	assert(pc);
	//增容
	checkcapacity(pc);
	
	printf("请输入联系人姓名\n");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入联系人年龄\n");
	scanf("%d", &pc->date[pc->count].age);
	printf("请输入联系人性别\n");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入联系人电话\n");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入联系人地址\n");
	scanf("%s", pc->date[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}


void showcontact(const contact* pc)
{
	assert(pc);
	printf("%30s\t%5s\t%10s\t%20s\t%30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
			return i;//返回下标
		}
	}return -1;
}

void subcontact(contact* pc)
{
	char name[name_max] = { 0 };
	assert(pc);
	if (pc->count==0)
	{
		printf("通讯录是空的\n");
		return;
	}
	printf("请输入要删除的联系人名字\n");
	scanf("%s", name);
	int ret = 0;
	//1. 查找
	ret = find( pc, name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2. 删除
	for (int i =ret; i < pc->count-1; i++)//将每个元素都向前覆盖一位，然后count-- 目的为了让属于ret下标的元素消失！
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

void searchcontanct(contact* pc)
{
	assert(pc);
	char name[name_max] = { 0 };
	int ret = 0;
	printf("请输出要搜索的人的名");
	//1. 查找
	ret = find(pc, name);
	if (ret == -1)
	{
		printf("要搜索的人不存在\n");
		return;
	}
	//2.打印
	printf("%30s\t%5s\t%10s\t%20s\t%30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输出要修改的人的名\n");
	//1. 查找
	ret = find(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("已经查询到要修改的人，接下来开始进行修改");
	//2.修改
	printf("请输入联系人姓名\n");
	scanf("%s", pc->date[ret].name);
	printf("请输入联系人年龄\n");
	scanf("%d", &pc->date[ret].age);
	printf("请输入联系人性别\n");
	scanf("%s", pc->date[ret].sex);
	printf("请输入联系人电话\n");
	scanf("%s", pc->date[ret].tele);
	printf("请输入联系人地址\n");
	scanf("%s", pc->date[ret].addr);
	printf("修改成功");
}

int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((peoinfo*)e1)->name , ((peoinfo*)e2)->name);
}

void sqrtcontact(contact* pc)
{
	assert(pc);
	qsort(pc->date, pc->count, sizeof(peoinfo), cmp_name);
	printf("排序成功\n");
}

void savecontact(contact* pc)
{
	//创建文件
	assert(pc);
	FILE* pf = fopen("contact.txt", "wb");
	if (pf==NULL)
	{
		perror("savecontact");
		return 1;
	}
	//写文件
	for (int i = 0; i < pc->count; i++)
	{
		fwrite(pc->date+i, sizeof(peoinfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

void loadcontact(contact* pc)
{
	//打开文件
	assert(pc);
	FILE* pf_read = fopen("contact.txt", "rb");
	if (pf_read==NULL)
	{
		perror(loadcontact); 
		return 1;
	}
	//读取文件
	peoinfo tep = { 0 };//创建临时变量 防止通讯录因空间不够而无法存储
	while (fread(&tep,sizeof(peoinfo),1,pf_read)==1)
	{
		checkcapacity(pc);

		pc->date[pc->count] = tep;
		pc->count++;
	}
	fclose(pf_read);
	pf_read = NULL;
}