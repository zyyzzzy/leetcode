/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
*/


 struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL)    return head;

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while(true)
    {
        if(fast == NULL || fast->next == NULL)  return NULL; //如果么有环则直接返回，如果只有一个节点，则也直接返回。
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)    break;  //说明有环。
    }
    fast = head;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}