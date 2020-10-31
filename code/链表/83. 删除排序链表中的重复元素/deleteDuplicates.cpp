/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/


 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)     return head;

        ListNode *p = head;
        ListNode *tmp;

        while(p != nullptr && p->next != nullptr)
        {
            tmp = p->next;
            if(p->val == tmp->val)
            {
                p->next = tmp->next;
                delete tmp;
            }
            else       p = p->next;   //注意if else 结构！
            
        }
        return head;  
    }
};