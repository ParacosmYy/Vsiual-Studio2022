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
//ѧ��������Ϣ
typedef struct people
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char tele[tele_max];
	char addr[addrr_max];
}peoinfo;

//��̬ͨѶ¼��Ϣ
//typedef struct contact
//{
//	peoinfo date[100];
//	int count;//��¼ͨѶ¼���������ĸ���
//}contact;

//��̬ͨѶ¼�汾
typedef struct contact
{
	peoinfo* date;//����˵���Ϣ
	int count;//��¼ͨѶ¼���������ĸ���
	int capacity;//��ǰͨѶ¼������
}contact;
//��ʼͨѶ¼
int initcontact(contact* pc);


//����ͨѶ¼
void destroycontact(contact* pc);

//����������Ϣ
void addcontact(contact* pc);

//չʾ������Ϣ
void showcontact(const contact* pc);

//����������Ϣ
int find(contact* pc, char name[]);


//ɾ��������Ϣ
void subcontact(contact* pc);

//����������Ϣ
void searchcontanct(contact* pc);

//�ı�������Ϣ
void modifycontact(contact* pc);

//����������Ϣ
void sqrtcontact(contact* pc);

//����������Ϣ
void savecontact(contact* pc);

//����
int checkcapacity(contact* pc);

//����������Ϣ
void loadcontact(contact* pc);