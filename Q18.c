#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SListNode
{
    int val;
    struct SListNode *next;
    struct SListNode *random;
} Node;

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    // 复制产生新链表并链接
    Node *Cur = head;
    Node *Next = head->next;
    while (Cur)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = Cur->val;
        newNode->random = NULL;
        newNode->next = Cur->next;
        Cur->next = newNode;
        Cur = Next;
        if (Next)
            Next = Next->next;
    }
    // 处理复制链表的random
    Cur = head;
    Node *Copy = head->next;
    Next = Copy->next;
    while (Cur)
    {
        if (Cur->random == NULL)
        {
            Copy->random = NULL;
        }
        else
        {
            Copy->random = (Cur->random)->next;
        }
        Cur = Next;
        if (Next)
        {
            Copy = Next->next;
            Next = Next->next->next;
        }
    }
    // 断开链表
    Cur = head;
    Node *Copy_head = head->next;
    Copy = Copy_head;
    while (Cur)
    {
        Cur->next = Cur->next->next;
        if (Copy->next)
        {
            Copy->next = Copy->next->next;
        }
        Cur = Cur->next;
        Copy = Copy->next;
    }
    return Copy_head;
}

