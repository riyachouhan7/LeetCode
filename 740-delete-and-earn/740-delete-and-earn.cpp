class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }
        
        int result = nums[0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j] || nums[i] > nums[j] + 1) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                    result = max(result, dp[i]);
                }
            }
        }
        return result;
    }
};