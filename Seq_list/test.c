#include "linked_list.h"

int main(){
    SL seql;
    SeqLListInit(&seql);
    for(int i = 0;i<10;i++){
        SeqLListPushBack(&seql,i);
    }
    SeqLListPrint(&seql);
    SeqLListPushFront(&seql,10);
    SeqLListPrint(&seql);
    SeqLListPopBack(&seql);
    SeqLListPrint(&seql);
    SeqLListPopFront(&seql);
    SeqLListPrint(&seql);
    SeqLListInsert(&seql,5,6);
    SeqLListPrint(&seql);
    SeqLListErase(&seql,5);
    SeqLListPrint(&seql);  
}