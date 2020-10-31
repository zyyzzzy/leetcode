/*
编写一个程序，找到两个单链表相交的起始节点。
注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

*/


  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA ==nullptr ||headB == nullptr)  return nullptr;

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while(p1 != p2)
        {
            if(p1 == nullptr)     //p1 = ((p1 == null)?headB:p1->next)
            {
                p1 = headB;
            }
            else
                p1 = p1->next;

            if(p2 == nullptr)    //p2 = ((p2 == null)?headA:p2->next)
            {
                p2 = headA;
            }
            else
                p2 = p2->next;   
        }
        return p1;

    
    }
};