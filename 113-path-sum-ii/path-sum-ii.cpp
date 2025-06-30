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

    void helper(TreeNode* root, int targetSum, int currSum, vector<int>& path) {
        if (!root) return;

        currSum += root->val;
        path.push_back(root->val);

        // Check if it's a leaf node and sum matches
        if (!root->left && !root->right && currSum == targetSum) {
            ans.push_back(path);  // Store a copy of path
        }

        // Recurse left and right
        helper(root->left, targetSum, currSum, path);
        helper(root->right, targetSum, currSum, path);

        path.pop_back();  // Backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper(root, targetSum, 0, path);
        return ans;
    }
};
