#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct SListNode
{
    int data;
    SListNode* next;
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

void deleteNode(SListNode** Pphead, int val) {
    if (Pphead == NULL || *Pphead == NULL) {
        printf("空链表\n");
        return;
    }

    SListNode* Cur = *Pphead;
    SListNode* Prev = NULL;

    // 情况 1：删除头节点
    if (Cur->data == val) {
        *Pphead = Cur->next;
        free(Cur);  // 别忘了释放内存
        return;
    }

    // 情况 2：删除中间或尾部节点
    while (Cur != NULL) {
        if (Cur->data == val) {
            Prev->next = Cur->next;
            free(Cur);  // 释放内存
            Cur = Prev->next;
        }
        else{
            Prev = Cur;
            Cur = Cur->next;
        }
    }

    // 如果没找到
    printf("未找到要删除的节点值 %d\n", val);
}

// struct ListNode* deleteNode(struct ListNode* head, int val) {
//     if(head == NULL){
//         printf("链表为空！");
//         return head;
//     }
//     //删除头节点
//     struct ListNode* Cur = head;
//     struct ListNode* Prev = NULL;
//     if(head->val == val){
//         head = Cur->next;
//         free(Cur);
//         return head;
//     }
//     while (Cur != NULL)
//     {
//         if(Cur->val == val){
//             Prev->next = Cur->next;
//             free(Cur);
//             // return head;
//             Cur = Prev->next;
//         }
//         else{
//             Prev = Cur;
//             Cur = Cur->next;
//         }
//     }
//     return head;
// }


int main(){
    SListNode* phead = NULL;
    SListPush(&phead,6);
    SListPush(&phead,1);
    SListPush(&phead,-3);
    SListPush(&phead,2);
    SListPush(&phead,6);
    SListPush(&phead,9);
    deleteNode(&phead,6);
    SListPrint(&phead);
}