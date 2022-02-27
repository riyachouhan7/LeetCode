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
    
    // level,index
    map<int, int> m;
    unsigned int maxWidth = 0;
    
    void dfs(TreeNode* node, int level, unsigned int index) {
        if (node == NULL)
            return;
        
        if (m.find(level) == m.end())
            m[level] = index;
        maxWidth = max(maxWidth, index - m[level] + 1);
        
        dfs(node->left, level+1, 2*index+1);
        dfs(node->right, level+1, 2*index+2);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        
        return maxWidth;
    }
};