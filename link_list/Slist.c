#include "Slist.h"   


void SListPrint(SListNode* Phead){
    //不需要声明空指针，因为链表本来就可能是空的
      SListNode* Cur = Phead;
      while (Cur !=NULL)
      {
        printf("%d-> ",Cur->data);
        Cur = Cur->next;
      }
      printf("NULL\n");
      return; 
}

SListNode* BuySListNode(SListDataType x){
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if(newNode == NULL){
        perror("malloc");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

//尾插，尾删
void SListPushBack(SListNode** PPhead,SListDataType x){
    if(*PPhead ==NULL){
        SListNode* newNode = BuySListNode(x);
        *PPhead = newNode;
    }
    else{
        SListNode* tail = *PPhead;
        while (tail->next !=NULL)
        {
            tail = tail->next;
        }
        SListNode* newNode = BuySListNode(x);
        tail->next = newNode;
    }
    return;
}

void SListPopBack(SListNode** PPhead){
    if(*PPhead = NULL){
        printf("空链表！\n");
        return;
    }
    else if (((*PPhead)->next == NULL))
    {
        free(*PPhead); 
        *PPhead = NULL;
    }
    
    else{
        SListNode* Cur = *PPhead;
        while (Cur->next !=NULL)
        {
            Cur = Cur->next;
        }
        free(Cur);
        Cur = NULL;
    }
}

//头插，头删
void SListPushFront(SListNode** PPhead,SListDataType x){
    if(*PPhead = NULL){
        (SListNode* front)
    }
}
void SListPopFront(SListNode** PPhead);
