Day-1  Binary Tree Maximum Path Sum.cpp


/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxPathSum_util(TreeNode *root,int &result)
    {
        if(!root)
            return 0;
        
        int left = maxPathSum_util(root->left,result);
        int right = maxPathSum_util(root->right,result);
        
        int max_straight = max(max(left,right)+root->val, root->val);
        int max_caseVal = max(max_straight,left+right+root->val);
        result = max(max_caseVal,result);
        
        return max_straight;
    }
public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = INT_MIN;
        maxPathSum_util(root,result);
        return result; 
    }
};
