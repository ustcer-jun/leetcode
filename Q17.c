struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    struct ListNode* Fast = head;
    struct ListNode* Slow = head;
    while (Fast && Fast->next)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
        if(Slow == Fast){
            break;
        }
    }
    // 没有环
    if (!Fast || !Fast->next){
        return NULL;
    }
    struct ListNode* pA = Slow;
    struct ListNode* pB = head;
    while (pA != pB)
    {
        pA = pA->next;
        pB = pB->next;
    }
    return pA;
}