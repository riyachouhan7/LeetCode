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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        pre(root, ans);

        unordered_map<int, int> freq;

        vector<int> temp;

        int maxx = INT_MIN;

        for(auto it: ans){
            freq[it]++;
            maxx = max(freq[it], maxx);

        }
        for(auto it : freq){
            if(it.second == maxx){
                temp.push_back(it.first);
            }
        }
        return temp;

        

    }
    void pre(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);

    }
};