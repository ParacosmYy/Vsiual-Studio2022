#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist(); /*裁判实现，细节不表*/
struct ListNode* reverse(struct ListNode* head);
void printlist(struct ListNode* head)
{
    struct ListNode* p = head;
    while (p) 
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* head;

    head = createlist();
    head = reverse(head);
    printlist(head);

    return 0;
}

struct ListNode *createlist()
{
    int data = 0;
    struct ListNode* head;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    while (scanf("%d",&data)&&data!=-1)
    {
        struct ListNode* p = NULL;
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->data = data;
        p->next = NULL;
                struct ListNode* lastnode=head;
                while (lastnode->next!=NULL)
                {
                    lastnode = lastnode->next;
                }
                lastnode->next = p;
    }
    return head;
}

struct ListNode *reverse(struct ListNode* head)//链表逆置函数
{
    
    struct ListNode* l;
    l = (struct ListNode*)malloc(sizeof(struct ListNode));
    l = head;
    struct ListNode* begin = l->next;
    struct ListNode* end = l->next->next;
    while (end != NULL)
    {
        begin->next = end->next;
        end->next = l->next;
        l->next = end;
        end = begin->next;
    }
    return head->next;
}