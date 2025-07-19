class Solution {
    int helper(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(target == 0) return 0;
        if(ind < 0 && target != 0) return INT_MIN;
        if(dp[ind][target] != -1) return dp[ind][target];

        int take = INT_MIN;;
        if(nums[ind] <= target) {
            take = 1 + helper(ind-1, nums, target-nums[ind], dp);
        }
        int not_take = helper(ind-1, nums, target, dp);
        return dp[ind][target] = max(take, not_take);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1, -1));
        int ans = helper(n-1 ,nums,target,dp);
        if(ans < 0) return -1;
        else return ans;
    }
};