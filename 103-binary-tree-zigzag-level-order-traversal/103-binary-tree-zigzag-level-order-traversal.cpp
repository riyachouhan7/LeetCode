class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>res;
        if(root==NULL)return res;
         
        queue<TreeNode *>nodes;
        nodes.push(root);
        bool left_to_right=true;
        while(!nodes.empty())
        {
            int size=nodes.size();
            vector<int>row(size);
            int index=-1;
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=nodes.front();
                if(left_to_right)
                    index=i;
                else index=size-i-1;
                row[index]=curr->val;
                
                if(curr->left)nodes.push(curr->left);
                if(curr->right)nodes.push(curr->right);
                
                nodes.pop();
            }
            res.push_back(row);
            left_to_right=!left_to_right;
        }
        return res;
    }
};

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
