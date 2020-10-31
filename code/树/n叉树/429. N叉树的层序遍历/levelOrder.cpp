/*
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
*/
/*
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
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root == nullptr)     return res;
        queue<Node*>que;
        que.push(root);

        while(!que.empty())
        {
            vector<int>tmp;
            int len = que.size();
            for(int i = 0 ; i < len; i++)
            {
                Node* cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                for(int j =0 ; j < cur->children.size();j++)
                {
                    que.push(cur->children[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;

        
    }
};