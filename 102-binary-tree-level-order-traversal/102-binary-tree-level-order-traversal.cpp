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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
    
    void helper(TreeNode* root, int level) {
        if(!root)  return;
        if(ans.size() == level) ans.push_back({root -> val});
        else ans[level].push_back(root -> val);
        helper(root -> left, level + 1);
        helper(root -> right, level + 1);
    }
};