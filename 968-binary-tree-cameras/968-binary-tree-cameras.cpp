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
    int noofCameras = 0;
    int minCameraCover(TreeNode* root) 
    {
        if(Camera(root)=="want")
            noofCameras++;
        return noofCameras;
    }
    string Camera(TreeNode* root)
    {
        if(root==NULL)
            return "ok";
        string left = Camera(root->left);
        string right = Camera(root->right);
        
        if(left=="want" || right=="want")
        {
            noofCameras++;
            return "provide";
        }
        else if(left=="provide" || right=="provide")
            return "ok";
        return "want";
    }
};