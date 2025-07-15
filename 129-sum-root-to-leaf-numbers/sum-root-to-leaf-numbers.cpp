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
    void dfs(TreeNode* root, int currentNum, int &totalSum) {
        if(!root) return;

        currentNum = currentNum * 10 + root->val;

        if(!root->left && !root->right)
        {
            totalSum += currentNum;
        }

        dfs(root->left, currentNum, totalSum);
        dfs(root->right, currentNum, totalSum);
    }
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        dfs(root, 0, totalSum);
        return totalSum;
    }
};