/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/


 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr)   return l2;
        if(l2 == nullptr)   return l1;

        ListNode *prehead = new ListNode(-1); //创建一个叫prehead的节点。
        ListNode *prev = prehead;//定义一个叫prev的指针指向prehead节点。

        while(l1 != nullptr && l2!=nullptr)
        {
            if(l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
                prev =prev->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
                prev =prev->next;
            }
        }
        if((prev->next = l1) == nullptr) //最多有一个还没有被合并，所以直接将prev->next 指向其中一个的链尾。
            prev->next = l2;
        else
            prev->next = l1;

        return prehead->next;
        
        
    }
};