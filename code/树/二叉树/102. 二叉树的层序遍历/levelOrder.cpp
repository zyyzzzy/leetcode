/*给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

*/


Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr)     return res;
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty())
        {
            vector<int>tmp;
            int len = que.size();
            for(int i = 0 ; i < len ; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                
                if(cur->left)       que.push(cur->left);
                if(cur->right)      que.push(cur->right);
            }    
            res.push_back(tmp);
        }
        return res;
        
        
    }
};