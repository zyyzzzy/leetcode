/*删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)     return head;

        ListNode *p = head;
        ListNode *del;

        while( p->next != nullptr)
        {
            if(p->next->val == val)
            {
                del = p->next; //暂存要删除的节点
                p->next = del->next;//连接1 3 节点
                delete del;//删除第二个节点（释放）
            }
            else
                p = p->next;
        }

        if(head->val == val)
        {
            del = head;
            head = head->next;
            delete del;
            return head;
        }
        return head;
    }
};

