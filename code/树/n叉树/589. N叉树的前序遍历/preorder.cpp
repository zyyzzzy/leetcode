/*
给定一个 N 叉树，返回其节点值的前序遍历。
*/



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    void pre(Node* root,vector<int>&res) 
    {
        if(root == nullptr)     return;
        res.push_back(root->val);
        vector<Node*>::iterator cur;
        cur = root->children.begin();//cur是一个二维指针
        //auto cur = root->children.begin();   这也是其中一种定义迭代器的方法，这种方便。
        for(; cur!=root->children.end();cur++)
        {
            pre(*cur,res);//*cur是一个指向children的指针。
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>res;
        pre(root,res);
        return res;
    }
};