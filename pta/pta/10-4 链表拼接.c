#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist(); 
struct ListNode* mergelists(struct ListNode* list1, struct ListNode* list2);
void printlist(struct ListNode* head)
{
    struct ListNode* p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* list1, * list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

    return 0;
}


struct ListNode* createlist()
{
    struct ListNode* p = NULL, * head = NULL, * lastnode = NULL;
  
    while (1)
    {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &p->data);
        p->next = NULL;
        if (p->data == -1)
        {
            break;
        }
        if (head == NULL)
        {
            head = p;
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
struct ListNode* mergelists(struct ListNode* list1, struct ListNode* list2)//ÉýÐòÁ´±íÆ´½Ó
{
    struct ListNode* list3, * p, * q, * r;
    list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = list1;
    q = list2;
    r = (struct ListNode*)malloc(sizeof(struct ListNode));
    r->next = list3 = list1;
    while (p&&q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q; 
            q = q->next;
        }
    }
    if (p)
    {
        r->next = p;
    }
    if (q)
    {
        r->next = q;
    }
    return list1;
}
