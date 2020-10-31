/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr)     return res;
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty())
        {
            vector<int>tmp;
            int len = que.size();
            for(int i=0 ;i<len;i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                
                if(cur->left)   que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());  //翻转res，将最后面的数字变成第一个，第一个变成最后一个。
        return res;
    }
};