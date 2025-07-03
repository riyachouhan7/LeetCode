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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>res;
        if(root==NULL) return res;
         
        queue<TreeNode *>q;
        q.push(root);
        bool LR = 1;
        while(!q.empty()) {
            int n = q.size();
            vector<int> row(n);
            for(int i=0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();

                if(LR==1) row[i]=node->val;
                else row[n-i-1]=node->val;

                if(node->left) q.push(node->left);

                if(node->right) q.push(node->right);
            }
            LR = !LR;
            res.push_back(row);
        }
        return res;
    }
};