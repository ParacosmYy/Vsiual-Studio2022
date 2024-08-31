#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
    int    num;
    char   name[20];
    int    score;
    struct stud_node* next;
};
struct stud_node* head, * tail;

void input();

int main()
{
    struct stud_node* p;

    head = tail = NULL;
    input();
    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

void input()
{
    struct stud_node* p;
    int    num;
    char   name[20];
    int    score;
    p = NULL;
    scanf("%d %s %d", &num, &name, &score);
    while (num!=0)
    {
        p = (struct stud_node*)malloc(sizeof(struct stud_node));
        p->num = num;
        strcpy(p->name, name);
        p->score = score;
        p->next = NULL;
        if (head==NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            head = p;
            tail->next = p;
        }
        scanf("%d %s %d", &num, &name, &score);
    }
}