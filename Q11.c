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

 SListNode* mergeTwoLists(SListNode* list1,SListNode* list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    SListNode* head = NULL;
    SListNode* tail = NULL;
    if(list1->data > list2->data){
        head = list2; 
        tail = list2;
        list2 = list2->next;
    }
    else{
        head = list1; 
        tail = list1;
        list1 = list1->next;
    }
    while (list1 && list2)
    {
        if(list1->data < list2->data){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if(list1){
        tail->next = list1;
    }
    if(list2){
        tail->next = list2;
    }
    return head;
}

 SListNode* mergeTwoLists(SListNode* list1,SListNode* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    SListNode Dummy;
    Dummy.next = NULL;
    SListNode* tail = &Dummy;
    while (list1 && list2)
    {
        if(list1->data <list2->data){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail= tail->next;
    }

    if(list1){
        tail->next = list1;
    }
    if(list2){
        tail->next = list2;
    }
    return Dummy.next;
}


int main(){
    SListNode* phead1 = NULL;
    SListNode* phead2 = NULL;
    SListPush(&phead1,1);
    SListPush(&phead1,3);
    SListPush(&phead1,5);
    SListPush(&phead1,7);
    SListPush(&phead2,2);
    SListPush(&phead2,4);
    SListPush(&phead2,6);
    SListPush(&phead2,8);
    SListPrint(&phead1);
    SListPrint(&phead2);
    SListNode* new_head = mergeTwoLists(phead1,phead2);
    SListPrint(&new_head);
}