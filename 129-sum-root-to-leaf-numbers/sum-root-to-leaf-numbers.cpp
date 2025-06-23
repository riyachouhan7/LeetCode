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
    void dfs(TreeNode* node, string currentPath, int &totalSum) {
        if (!node) return;

        currentPath += to_string(node->val);

        // If leaf node
        if (!node->left && !node->right) {
            totalSum += stoi(currentPath); // Convert path string to integer
            return;
        }

        dfs(node->left, currentPath, totalSum);
        dfs(node->right, currentPath, totalSum);
    }

    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        dfs(root, "", totalSum);
        return totalSum;
    }
};