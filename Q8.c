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
// void reverseList(SListNode** Pphead){
//     assert(Pphead);
//     if(*Pphead == NULL || (*Pphead)->next == NULL){
//         return;
//     }
//     SListNode* Node1 = NULL;
//     SListNode* Node2 = *Pphead;
//     SListNode* Node3 = Node2->next;
//     while (Node2)
//     {
//         Node2->next = Node1;
//         Node1 = Node2;
//         Node2 = Node3;
//         if(Node3){
//             Node3 = Node3->next;
//         }
//     }
//     *Pphead = Node1;
// }

// SListNode* reverseList(SListNode* Pphead){
//     // assert(Pphead);
//     if(Pphead == NULL || Pphead->next == NULL){
//         return Pphead;
//     }
//     SListNode* Node1 = NULL;
//     SListNode* Node2 = Pphead;
//     SListNode* Node3 = Node2->next;
//     while (Node2)
//     {
//         Node2->next = Node1;
//         Node1 = Node2;
//         Node2 = Node3;
//         if(Node3){
//             Node3 = Node3->next;
//         }
//     }
//     return Node1;
// }

// SListNode* reverseList(SListNode* Pphead){
//     // assert(Pphead);
//     if(Pphead == NULL || Pphead->next == NULL){
//         return Pphead;
//     }
//     SListNode* Cur = Pphead;
//     SListNode* New_head = NULL;
//     SListNode* NEXT = Pphead->next;
//     while (Cur)
//     {
//         Cur->next = New_head;
//         New_head = Cur;
//         Cur = NEXT;
//         if(NEXT){
//             NEXT = NEXT->next;
//         }
//     }
//     return New_head;
// }


SListNode* reverseList(SListNode* Pphead){
    if(Pphead ==NULL || Pphead->next == NULL){
        return Pphead; 
    }
    SListNode* New_head = reverseList(Pphead->next);

    Pphead->next->next = Pphead;
    Pphead->next = NULL;

    return New_head;
}


// SListNode* reverseList(SListNode* Phead) {
//     // 空链表 或 只有一个节点，直接返回
//     if (Phead == NULL || Phead->next == NULL) {
//         return Phead;
//     }

//     // 递归反转子链表
//     SListNode* newHead = reverseList(Phead->next);

//     // 当前节点挂到子链表尾部
//     Phead->next->next = Phead;
//     Phead->next = NULL;

//     return newHead;
// }


int main(){
    SListNode* phead = NULL;
    SListPush(&phead,1);
    SListPush(&phead,2);
    SListPush(&phead,3);
    SListPush(&phead,4);
    SListPrint(&phead);
    SListNode* New_head = reverseList(phead);
    SListPrint(&New_head);
}