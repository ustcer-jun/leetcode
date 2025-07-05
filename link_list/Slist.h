#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;


typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
    
}SLTNode,SListNode;

void SListPrint(SListNode* Phead);

SListNode* BuySListNode(SListDataType x);   
//尾插，尾删
void SListPushBack(SListNode** Phead,SListDataType x);
void SListPopBack(SListNode** Phead);

//头插，头删
void SListPushFront(SListNode** Phead,SListDataType x);
void SListPopFront(SListNode** Phead);