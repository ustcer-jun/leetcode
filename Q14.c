#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

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
bool isPalindrome(SListNode* phead) {
    if(phead == NULL || phead->next == NULL){
        return true;
    }
    //利用快慢指针，找到中间节点！
    SListNode* slow = phead;
    SListNode* fast = phead;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //slow此时为左中间节点，指向右中间节点
    //将后面节点进行反转
    SListNode* prev = NULL;
    SListNode* cur = slow->next;
    while (cur)
    {
        SListNode* Next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = Next;
    }
    SListNode* p1 = prev;
    SListNode* p2 = phead;
    while (p1)
    {
        if(p1->data != p2->data){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
// bool isPalindrome(SListNode* phead) {
//     if(phead == NULL || phead->next == NULL){
//         return true;
//     }

//     // 找到中点（slow指向前半段末尾）
//     SListNode* slow = phead;
//     SListNode* fast = phead;
//     while (fast->next && fast->next->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // 反转右半部分
//     SListNode* prev = NULL;
//     SListNode* cur = slow->next;
//     while (cur) {
//         SListNode* next = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = next;
//     }

//     // 比较左右两半部分
//     SListNode* p1 = phead;
//     SListNode* p2 = prev;
//     while (p2) {
//         if (p1->data != p2->data) {
//             return false;
//         }
//         p1 = p1->next;
//         p2 = p2->next;
//     }

//     return true;
// }

int main(){
    SListNode* phead = NULL;
    SListPush(&phead,1);
    SListPush(&phead,2);
    SListPush(&phead,3);
    // SListPush(&phead,6);
    // SListPush(&phead,9);
    // SListPush(&phead,6);
    // SListPush(&phead,5);
    SListPush(&phead,2);
    SListPush(&phead,1);
    SListPrint(&phead);
    if(isPalindrome(phead)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}