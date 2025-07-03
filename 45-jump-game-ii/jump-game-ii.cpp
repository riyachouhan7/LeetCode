class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size() - 1) return 0; // Reached or surpassed the end
        if (dp[index] != -1) return dp[index];  // Already calculated

        int minJumps = nums.size(); // Worst case max n-1 jumps

        for (int i = 1; i <= nums[index]; i++) { // Try all possible jumps
            minJumps = min(minJumps, 1 + solve(nums, index + i, dp));
        }
        return dp[index] = minJumps;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // use -1 to indicate "not calculated"
        return solve(nums, 0, dp);
    }
};
