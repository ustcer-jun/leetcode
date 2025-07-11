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

SListNode* partition(SListNode* head, int x){
    if(head == NULL || head->next == NULL){
        return head;
    }
    SListNode*Cur = head;
    SListNode LessList;
    SListNode* Tail_Less = &LessList;
    SListNode GreatList;
    SListNode* Tail_Great = &GreatList;
    while (Cur)
    {
        //注意把新的节点加入到新链表中需要断掉之前的链接
        SListNode* next = Cur->next;
        Cur->next = NULL;
        if(Cur->data <= x){
            Tail_Less->next = Cur;
            Tail_Less = Tail_Less->next;
        }
        else{
            Tail_Great->next = Cur;
            Tail_Great = Tail_Great->next;
        }
        Cur = next;
    }
    Tail_Less->next = GreatList.next;
    return LessList.next;
}


int main(){
    SListNode* phead = NULL;
    SListPush(&phead,1);
    SListPush(&phead,3);
    SListPush(&phead,5);
    SListPush(&phead,7);
    SListPush(&phead,9);
    SListPush(&phead,2);
    SListPush(&phead,4);
    SListPush(&phead,6);
    SListPush(&phead,8);
    SListPush(&phead,10);
    SListPrint(&phead);
    SListNode* new_head = partition(phead,4);
    SListPrint(&new_head);
}