 #include "linked_list.h"

void SeqLListInit(SL* ps){
    assert(ps);
    ps->a = (SLDataType*) malloc(4*sizeof(SLDataType));
    ps->size = 0;
    ps->capacity = 4;
}

void SeqLListPrint(SL* ps){
    assert(ps);
    for (int i=0;i<ps->size;i++){
        printf("%d\t",ps->a[i]);
    }
    printf("\n");
}
//检查容量是否充足
void Check_capacity(SL* ps){
    assert(ps);
    if(ps->size >= ps->capacity){
        SLDataType* tmp = (SLDataType* ) realloc(ps->a,2*ps->capacity*sizeof(SLDataType));
        if(tmp == NULL){
            perror("realloc");
        }
         ps->a = tmp;
         ps->capacity +=  ps->capacity;
        tmp = NULL;
    }
}

//尾插
void SeqLListPushBack(SL* ps,SLDataType x){
    assert(ps);
    Check_capacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
} 
//头插
void SeqLListPushFront(SL* ps,SLDataType x){
    assert(ps);
    Check_capacity(ps);
    for(int i = ps->size;i>0;i--){
        ps->a[i] = ps->a[i-1];
    }
    ps->a[0] = x;
    ps->size++;
}
//尾删
void SeqLListPopBack(SL* ps){
    assert(ps);
    ps->a[ps->size] = 0;
    ps->size--;
}

//头删
void SeqLListPopFront(SL* ps){
    assert(ps);
    for(int i = 0;i<ps->size-1;i++){
        ps->a[i] = ps->a[i+1];
    }
    ps->size--;

}

// 任意位置的插入和删除
void SeqLListInsert(SL* ps,int pos,SLDataType x){
    assert(ps);
    Check_capacity(ps);
    for(int i = ps->size;i>pos;i--){
        ps->a[i] = ps->a[i-1];
    }
    ps->a[pos] = x;
    ps->size++;
    
}
void SeqLListErase(SL* ps,int pos){
    assert(ps);
    for(int i = pos;i<ps->size;i++){
        ps->a[i] = ps->a[i+1];
    }
    ps->size --;
}