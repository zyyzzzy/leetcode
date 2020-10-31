/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：

0 <= 节点个数 <= 5000

*/

/*
思路：
首先先判断头是否为空，如果空，则直接返回。
定义三个结构体指针。
画图！改变指针的指向！
*/

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)    return head;

    struct ListNode *p = head;
    struct ListNode *cur =NULL;
    struct ListNode *tmp;

    while(p != NULL)
    {
        tmp = p->next;   // 存储下一个节点的位置。
        p->next = cur;   
        cur = p;
        p = tmp;
    }

    return cur;
}