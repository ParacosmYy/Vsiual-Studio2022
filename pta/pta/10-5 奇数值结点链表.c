#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* readlist();
struct ListNode* getodd(struct ListNode** L);
void printlist(struct ListNode* L)
{
    struct ListNode* p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* L, * Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}


struct ListNode* readlist()//��װ����
{
    int data;
    struct ListNode* head = NULL;
    struct ListNode* lastnode = NULL;
    
    while (scanf("%d", &data) && data != -1)
    {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->data = data;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            head->next = NULL;
        }
        else
        {
            lastnode = head;
            while (lastnode->next != NULL)
            {
                lastnode = lastnode->next;
            }
            lastnode->next = p;
        }
    }
    return head;
}
struct ListNode* getodd(struct ListNode** L)
{
    struct ListNode* newhead = NULL, * newcurrent = NULL, * newprve = NULL;//���ڴ���������
    struct ListNode* newL = *L;//����ԭʼ����ı�ͷ
    struct ListNode* kill = NULL;
        struct ListNode* prve = (*L);//��ʼ��Ϊԭʼ����ı�ͷ������ɾ���ڵ�
    while (*L)//����ԭʼ����
    {
        if ((*L)->data % 2 == 1)
        {
            /*�����洢������Ϊ�������������ȡ��������һ���µ�����洢��
            Ȼ��ɾ��ԭʼ�����д洢�����ݵĽڵ㡣*/
            newcurrent = (struct ListNode*)malloc(sizeof(struct ListNode));
            if (newhead == NULL)
                newhead = newcurrent;
            else
                newprve->next = newcurrent;
            newcurrent->data = (*L)->data;
            newcurrent->next = NULL;
            newprve = newcurrent;
            if ((*L) == newL)//��ɾ�ڵ�������ͷ
                newL = newL->next;
            else
                prve->next = (*L)->next;//ɾ���ڵ�
            kill = (*L);
            (*L) = (*L)->next;
            free(kill);//�ͷ��ڴ�
        }
        else
        {
            prve = (*L);
            (*L) = (*L)->next;
        }
    }
    *L = newL;//L�д洢�ĵ�ַ��Ϊɾ��������ֵ����������ͷ����ַ
    return newhead;
}

