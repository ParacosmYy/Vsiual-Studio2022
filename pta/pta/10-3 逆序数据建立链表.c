#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist();

int main()
{
    struct ListNode* p, * head = NULL;

    head = createlist();
    for (p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

struct ListNode* createlist()
{
    struct ListNode* p = NULL, * head = NULL;
    while (1)
    {
        int temp = 0;
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (head==NULL)
        {
            if (scanf("%d",&temp)==0)
            {
                break;
            }
            p->data = temp;
            head = p;
            head->next = NULL;
        }
        else
        {
            scanf("%d", &p->data);
            if (p->data == -1)
            {
                return head;
                break;
            }
            p->next = head;
            head = p;
        }
    }

}