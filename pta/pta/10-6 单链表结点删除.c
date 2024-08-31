#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* readlist();
struct ListNode* deletem(struct ListNode* L, int m);
void printlist(struct ListNode* L)
{
    struct ListNode* p = L;
    while (p) 
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m;
    struct ListNode* L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode* readlist()
{
    int data;
    struct ListNode* p, * head=NULL, * lastnode=NULL;
    while (scanf("%d",&data)&&data!=-1)
    {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->data = data;
        p->next = NULL;
        if (head==NULL)
        {
            head = p;
        }
        else
        {
            lastnode = head;
            while (lastnode->next!=NULL)
            {
                lastnode = lastnode->next;
            }
            lastnode->next = p;
        }
    }
    return head;
}

struct ListNode* deletem(struct ListNode* L, int m)
{
    struct ListNode* kill = NULL;
    struct ListNode* prve = L;
    while (prve->next != NULL)
    {

        if (L->data == m)
        {
            kill = L;
            L = L->next;
            prve = prve->next;
            free(kill);
        }
        else
        {
            while (prve->next != NULL)
            {
                if (prve->next->data == m)
                {
                    kill = prve->next;
                    prve->next = prve->next->next;
                    free(kill);
                }
                else
                {
                    prve = prve->next;
                }
            }
        }
        if (prve->next==NULL&&prve->data==m)
        {
            return NULL;
        }
    }
    return L;

}