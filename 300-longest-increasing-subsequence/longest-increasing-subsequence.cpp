class Solution {
public:
    int helper(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){

        if(ind == nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; 

        if( prev == -1 || nums[ind] > nums[prev]){
            return dp[ind][prev+1] = max(1 + helper(nums,ind+1, ind, dp), helper(nums, ind+1, prev, dp));
        }
        
        else return dp[ind][prev+1] = helper(nums, ind+1, prev, dp);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return helper(nums, 0, -1, dp);
    }
};