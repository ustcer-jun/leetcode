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

// SListNode* removeNthFromEnd(SListNode* phead, int n){
//     if (phead == NULL){
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
//     printf("%d\n",count);
//     int target = count-n;
//     printf("%d\n",target);
//     if(target == 0){
//         SListNode* del = phead;
//         phead = phead->next;
//         free(del);
//         return phead;
//     }
//     else{
//         Cur = phead;
//         SListNode* Prev = NULL;
//         while(Cur)
//         {

//             index++;
//             Prev = Cur;
//             Cur = Cur->next;
//             if(index == target){
//                 Prev->next = Cur->next;
//                 free(Cur);
//                 return phead;
//             }
//         };
//         return phead;
//     }
// }

// SListNode* removeNthFromEnd(SListNode* phead, int n){
//     if(phead == NULL){
//         return phead;
//     }
//     //链表只有一个元素，且是我们要删除的元素。
//     if(phead->next == NULL && n == 1){
//         phead = NULL;
//         return phead;
//     }
//     SListNode* Fast = phead;
//     SListNode* Slow = phead;
//     int count =0;
//     while (Fast->next)
//     {
//         if(count >= n){
//            Slow = Slow->next; 
//         }
//         Fast = (Fast->next);
//         count++;
//     }
//     //循环结束后，发现我们要删除的是头元素。
//     if(count == n-1){
//         SListNode* del= phead;
//         phead = phead->next;
//         free(del);
//     }
//     else{
//         SListNode* del= Slow->next;
//         Slow->next = (Slow->next->next);
//         free(del);
//     }
//     return phead;
// }

// SListNode* removeNthFromEnd(SListNode* phead, int n){
//     if(phead == NULL){
//         return phead;
//     }
//     SListNode Dummy;
//     Dummy.next = phead;
//     SListNode* Fast = &Dummy;
//     SListNode* Slow = &Dummy;
//     int count = 0;
//     for(int i =0;i<n;i++){
//         if(Fast){
//             Fast = Fast->next;
//         }
//     }
//     while (Fast->next)
//     {
//         Fast = Fast->next;
//         Slow = Slow->next;
//     }
//     SListNode* Del = Slow->next;
//     Slow->next = Del->next;
//     free(Del);
//     return  Dummy.next;
// }

SListNode* removeNthFromEnd(SListNode* phead, int n){
    if(phead == NULL){
        return phead;
    }
    SListNode* Fast = phead;
    SListNode* Slow = phead;
    int count = n;
    while (count--)
    {   
        if(Fast){
            Fast = Fast->next;
        }
        // count = count-1;
    }
    printf("%d\n",count);
    while (Fast)
    {
        Fast = Fast->next;
        Slow = Slow->next;
    }
    if(count == -1){ //删除头指针
        SListNode* Del = phead;
        phead = Del->next;
        free(Del);
    }
    else{
        SListNode* Del = Slow->next;
        Slow->next = Del->next;
        free(Del);
    }
    return  phead;
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
    SListNode* new_head = removeNthFromEnd(phead,7);
    SListPrint(&new_head);
}