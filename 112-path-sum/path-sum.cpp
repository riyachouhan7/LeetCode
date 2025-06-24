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
// class Solution {
// public:
//     bool helper(TreeNode* root, int sum = 0, int targetSum)
//     {
//         if(!root) return 0;
//         sum =+ root->val;
//         helper(root->left, sum, targetSum);
//         helper(root->right, sum, targetSum);
//         if(sum == targetSum) return true;
//         return false;
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         return helper(root,0, targetSum;)
//     }
// };
class Solution {
public:
    bool helper(TreeNode* root, int sum, int targetSum) {
        if (!root) return false;
        sum += root->val;
        if (!root->left && !root->right) {
            return sum == targetSum;
        }
        return helper(root->left, sum, targetSum) || helper(root->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0, targetSum);
    }
};