#include "linked_list.h"

int main(){
    SL seql;
    SeqLListInit(&seql);
    for(int i = 0;i<10;i++){
        SeqLListPushBack(&seql,i);
    }
    SeqLListPushFront(&seql,10);
    SeqLListPopBack(&seql);
    SeqLListPopFront(&seql);
    SeqLListInsert(&seql,5,6);
    SeqLListPrint(&seql);
    SeqLListErase(&seql,5);
    SeqLListPrint(&seql);
}