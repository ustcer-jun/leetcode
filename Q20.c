#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef struct ListNode
{
    int data;
    struct ListNode* next;
}ListNode;

struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* prev = NULL;
    struct ListNode* Cur = head;
    struct ListNode* Next = head->next;

    while (Next)
    {
        if(Cur->data  != Next->data){
            prev = Cur;
            Cur = Next;
            Next = Next->next;
        }
        else{
            while (Next && Cur->data  == Next->data)
            {
                Next = Next->next;
                //头节点就是重复节点
                if(prev){
                    prev->next = Next;
                }
                else{
                    head = Next;
                }
            }
            while (Cur != Next)
            {
                ListNode* del = Cur;
                Cur =Cur->next
                free(del);
            }
            if(Next) //Next不为空指针
                Next = Next->next;  
        }
    }    
    return head;
}