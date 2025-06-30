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
    unordered_map<int, int> inorderIndexMap;
    int postIndex;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // Root value is the current last element in postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // If the node has no children
        if (inStart == inEnd) return root;

        // Find the index of this root in inorder traversal
        int inIndex = inorderIndexMap[rootVal];

        // Build right subtree first (because of postorder's reverse nature)
        root->right = helper(inorder, postorder, inIndex + 1, inEnd);
        root->left = helper(inorder, postorder, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        // Map values to their indices in inorder
        for (int i = 0; i < n; ++i)
            inorderIndexMap[inorder[i]] = i;

        return helper(inorder, postorder, 0, n - 1);
    }
};
