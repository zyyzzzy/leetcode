/*
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。
*/


struct ListNode {
     int val;
     struct ListNode *next;
 };
 


int kthToLast(struct ListNode* head, int k){
    if(head == NULL || k <= 0)  return -1;

    struct ListNode *s = head;
    struct ListNode *f = head;

    for(int i = 0;i < k;i++)
        f = f->next;
    while(f)
    {
        s = s->next;
        f = f->next;
    }

    return s->val;
