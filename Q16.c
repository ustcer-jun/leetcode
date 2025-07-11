#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>
typedef struct SListNode
{
    int data;
    struct SListNode* next;
}SListNode;

SListNode *detectCycle(SListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    SListNode* Fast = head;
    SListNode* Slow = head;
    SListNode* newnode = NULL;
    while (Fast && Fast->next)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
        if(Slow == Fast){
            newnode = Slow->next; 
            Slow->next = NULL;
            break;
        }
    }
    if(newnode == NULL){
        return NULL;
    }
    //交叉节点问题：
     SListNode* pA = head;
     SListNode* pB = newnode;
     while (pA || pB)
     {
        if(pA == pB){
            return pA;
        }
        pA = pA ? pA->next : newnode;
        pB = pB ? pB->next : head;
     }
    return NULL;    
}

SListNode *detectCycle(SListNode *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    SListNode* Fast = head;
    SListNode* Slow = head;
    SListNode* newnode = NULL;
    while (Fast && Fast->next)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
        if(Slow == Fast){
            break;
        }
    }
    // 没有环
    if (!Fast || !Fast->next){
        return NULL;
    }
    SListNode* pA = Slow->next;
    SListNode* pB = head;
    while (pA! = pB)
    {
        pA = pA->next;
        pB = pB->next;
    }
    return pA;