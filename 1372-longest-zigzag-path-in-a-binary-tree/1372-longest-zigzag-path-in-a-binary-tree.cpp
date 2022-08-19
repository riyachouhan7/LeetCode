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
public:
    int maxi=0;
    
    void zigZag(TreeNode*root,int left,int right){
        
        if(!root) return;
        
        maxi = max(maxi, left);
        maxi = max(maxi, right);
        
        zigZag(root->left, 0, left+1);
        zigZag(root->right, right+1, 0);
        
    }
    int longestZigZag(TreeNode* root) {
        
        int left = 0;
        int right = 0;
        
        zigZag(root, left, right);
        return maxi;
    }
};