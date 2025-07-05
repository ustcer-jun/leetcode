#include "Slist.h"

int main(){

    //通常情况下定义链表我们只定义一个头指针
    SLTNode* pList = NULL;
    // 不用初始化。
    SListPushBack(&pList,10);
    SListPrint(pList);
} 