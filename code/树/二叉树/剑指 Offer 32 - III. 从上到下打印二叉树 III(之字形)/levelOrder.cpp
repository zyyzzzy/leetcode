/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推
节点总数 <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr)     return res;
        queue<TreeNode*>que;
        que.push(root);
        int level = 1;

        while(!que.empty())
        {
            vector<int>tmp;
            int len = que.size();
            for(int i =0; i<len; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                if(cur->left)   que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
            if(level%2 == 0)
            reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            level++;
        }
        return res;
    }
};