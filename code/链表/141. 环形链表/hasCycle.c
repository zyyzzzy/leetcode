/*
给定一个链表，判断链表中是否有环。
*/



 struct ListNode {
      int val;
     struct ListNode *next;
 };
 
bool hasCycle(struct ListNode *head) {
    if(head == NULL)    return false;

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)    return true;
    }

    return false;
    
}