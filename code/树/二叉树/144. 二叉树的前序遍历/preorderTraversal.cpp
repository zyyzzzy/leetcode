/*
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/



Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void Traversal(TreeNode* root,vector<int>&res)
    {
        if(root == nullptr)     return;
        res.push_back(root->val);
        Traversal(root->left,res);
        Traversal(root->right,res);    
    }

    vector<int> preorderTraversal(TreeNode* root) {    //返回一个vector
        vector<int>res;
        Traversal(root,res);
        return res;
    }
};