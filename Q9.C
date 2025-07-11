#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct SListNode
{
    int data;
    struct SListNode* next;
}SListNode;

SListNode* BuyNewNode(SListNode** Pphead,int val){
    assert(Pphead);
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    newNode->data = val;
    newNode->next = NULL;
    return  newNode;
}

void SListPush(SListNode** Pphead,int val){
    assert(Pphead);
    SListNode* newNode = BuyNewNode(Pphead,val);
    if(*Pphead == NULL){
        *Pphead = newNode;
        return;
    }
    SListNode* Cur = *Pphead;
    while (Cur->next !=NULL)
    {
        Cur = Cur->next;
    }
    Cur->next = newNode;
    return;
}
void SListPrint(SListNode** Pphead){
    assert(Pphead);
    SListNode* Cur = *Pphead;
    while (Cur!=NULL)
    {
        printf("%d->",Cur->data);
        Cur = Cur->next;
    }
    printf("NULL\n"); 
}

// SListNode* middleNode(SListNode* phead){
//     if (phead == NULL || phead->next == NULL){
//         return phead;
//     }
//     int count = 0;
//     int index = 0;
//     SListNode* Cur = phead;
//     while(Cur)
//     {
//         count++;
//         Cur = Cur->next;
//     };
//     int mid = count/2+1;
//     Cur = phead;
//     while(Cur)
//     {
//         index++;
//         if(index == mid){
//             return Cur;
//         }
//         Cur = Cur->next;
//     };
//     return NULL;
// }

SListNode* middleNode(SListNode* phead){
    if(phead == NULL || phead->next == NULL){
        return phead;
    }
    SListNode* Fast = phead;
    SListNode* Slow = phead;
    while (Fast && Fast->next)
    {
        Slow = Slow->next;
        Fast = (Fast->next)->next;
    }
    return Slow;

}

int main(){
    SListNode* phead = NULL;
    SListPush(&phead,1);
    SListPush(&phead,2);
    SListPush(&phead,3);
    SListPush(&phead,4);
    SListPush(&phead,6);
    SListPush(&phead,0);
    SListPush(&phead,8);
    SListPrint(&phead);
    SListNode* New_head = middleNode(phead);
    SListPrint(&New_head);
}