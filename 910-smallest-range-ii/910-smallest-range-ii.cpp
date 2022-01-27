class Solution {
public:
    int smallestRangeII(vector<int>& nums, int K) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[n-1] - nums[0];
        int left = nums[0] + K;
        int right = nums[n-1] - K;
        
        for (int i = 0; i < n-1; i++) {
            int maximum = max(nums[i] + K, right);
            int minimum = min(left, nums[i + 1] - K);
            ans = min(ans, maximum - minimum);
        }
        return ans;
    }
};