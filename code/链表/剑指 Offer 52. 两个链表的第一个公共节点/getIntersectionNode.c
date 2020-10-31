/*
输入两个链表，找出它们的第一个公共节点。
*/


struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)  return NULL;

    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;

    while(p1 != p2)
    {
        if(p1 == NULL)  p1 = headB;
        else p1 = p1->next;

        if(p2 == NULL)  p2 = headA;
        else p2 = p2->next;
         /*
           p1 = (p1==NULL)?headB:p1->next;
           p2 = (p2==NULL)?headA:p2->next;
        */
    }
    return p1;
}