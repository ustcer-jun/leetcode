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

// SListNode *getIntersectionNode(SListNode *headA, SListNode *headB) {
//     if(headA == NULL || headB == NULL){
//         return NULL;
//     }   
//     int count_A = 0;
//     int count_B = 0;
//     SListNode* Cur_A = headA;
//     SListNode* Cur_B = headB;
//     while (Cur_A)
//     {
//         count_A++;
//         Cur_A = Cur_A->next;
//     }
//     while (Cur_B)
//     {
//         count_B++;
//         Cur_B = Cur_B->next;
//     }
//     SListNode* Cur_A = headA;
//     SListNode* Cur_B = headB;

//     while (Cur_A && Cur_B)
//     {
//         if(count_A > count_B){
//             Cur_A = Cur_A->next;
//             count_A--;
//         }
//         else if(count_A < count_B){
//             Cur_B = Cur_B->next;
//             count_B--;
//         }
//         else{
//             if(Cur_A == Cur_B){
//                 return Cur_A
//             }
//             Cur_A = Cur_A->next;
//             Cur_B = Cur_B->next;
//         }
//     }
//     return NULL
// }

SListNode *getIntersectionNode(SListNode *headA, SListNode *headB){
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    SListNode* pA = headA;
    SListNode* pB = headB;
    while (pA != pB)
    {
        pA = pA ? pA->next : headB; //走到链表末尾跳转到链表b
        pB = pB ? pB->next : headA  ; //走到链表末尾跳转到链表a
    }
    return pA;
    
}

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
