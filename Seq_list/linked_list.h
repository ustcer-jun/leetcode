#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//顺序表，有效数组在数组中必须是连续
//静态顺序表设计 （固定大小）

typedef int SLDataType;
// #define N 10

typedef struct SeqLList
{
     SLDataType* a;
     int size;   //有效数据的个数
     int capacity; //容量
}SL,SeqLList;
//顺序表初始化
void SeqLListInit(SL* ps);
void SeqLListDestroy(SL* ps);
// 打印顺序表
void SeqLListPrint(SL* ps);
//检查容量
void Check_capacity(SL* ps);

// 任意位置的插入和删除
void SeqLListInsert(SL* ps,int pos,SLDataType x);
void SeqLListErase(SL* ps,int pos);


// 尾插尾删，头插头删
void SeqLListPushBack(SL* ps,SLDataType x); //尾插
void SeqLListPushFront(SL* ps,SLDataType x);//头插
void SeqLListPopBack(SL* ps); // 尾删
void SeqLListPopFront(SL* ps);//头删

//顺序查找
int SeqLListFind(SL* ps,SLDataType x);