#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef struct ListNode
{
    int data;
    struct ListNode* next;
}ListNode;

struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* Cur = head->next;
    struct ListNode* new_head = head;
    new_head->next = NULL;
    while (Cur)
    {   
        struct ListNode* new_Cur = new_head;
        struct ListNode* Next = Cur->next;
        if(Cur->val < new_Cur->val){
            Cur->next = new_Cur;
            new_head = Cur;
        }
        else{
            struct ListNode* prev = new_Cur;
            new_Cur =new_Cur->next;
            while (new_Cur && Cur->val >= new_Cur->val)
            {
                prev = new_Cur;
                new_Cur =new_Cur->next;
            }
            prev->next = Cur; 
            Cur->next = new_Cur;
        }
        Cur = Next;
    }
    return new_head;
}