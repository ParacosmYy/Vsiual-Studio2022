#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include <assert.h>
#include<stdlib.h>
#define name_max 30
#define sex_max 10
#define tele_max 20
#define addrr_max 30
#define inc_max 3
#define in_max 2
//学生个人信息
typedef struct people
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char tele[tele_max];
	char addr[addrr_max];
}peoinfo;

//静态通讯录信息
//typedef struct contact
//{
//	peoinfo date[100];
//	int count;//记录通讯录所存放人物的个数
//}contact;

//动态通讯录版本
typedef struct contact
{
	peoinfo* date;//存放人的信息
	int count;//记录通讯录所存放人物的个数
	int capacity;//当前通讯录的容量
}contact;
//初始通讯录
int initcontact(contact* pc);


//销毁通讯录
void destroycontact(contact* pc);

//增添人物信息
void addcontact(contact* pc);

//展示人物信息
void showcontact(const contact* pc);

//查找人物信息
int find(contact* pc, char name[]);


//删除人物信息
void subcontact(contact* pc);

//搜索人物信息
void searchcontanct(contact* pc);

//改变人物信息
void modifycontact(contact* pc);

//排序人物信息
void sqrtcontact(contact* pc);

//保存人物信息
void savecontact(contact* pc);

//增容
int checkcapacity(contact* pc);

//加载人物信息
void loadcontact(contact* pc);