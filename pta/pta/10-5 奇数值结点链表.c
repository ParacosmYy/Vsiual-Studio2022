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


struct ListNode* readlist()//组装链表
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
    struct ListNode* newhead = NULL, * newcurrent = NULL, * newprve = NULL;//用于创建新链表
    struct ListNode* newL = *L;//保存原始链表的表头
    struct ListNode* kill = NULL;
        struct ListNode* prve = (*L);//初始化为原始链表的表头，用于删除节点
    while (*L)//遍历原始链表
    {
        if ((*L)->data % 2 == 1)
        {
            /*遇到存储的数据为奇数的链表就提取出来创建一个新的链表存储，
            然后删除原始链表中存储该数据的节点。*/
            newcurrent = (struct ListNode*)malloc(sizeof(struct ListNode));
            if (newhead == NULL)
                newhead = newcurrent;
            else
                newprve->next = newcurrent;
            newcurrent->data = (*L)->data;
            newcurrent->next = NULL;
            newprve = newcurrent;
            if ((*L) == newL)//被删节点是链表头
                newL = newL->next;
            else
                prve->next = (*L)->next;//删除节点
            kill = (*L);
            (*L) = (*L)->next;
            free(kill);//释放内存
        }
        else
        {
            prve = (*L);
            (*L) = (*L)->next;
        }
    }
    *L = newL;//L中存储的地址改为删除了奇数值结点后的链表的头结点地址
    return newhead;
}

