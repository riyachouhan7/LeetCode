class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        int maxx = 0;
        int n = nums.size();

        // Left to right
        for (int i = 1; i < n; i++) {
            if (nums[i] < maxx && nums[i - 1] < nums[i]) {
                ans++;
            }
            maxx = max(maxx, nums[i - 1]);
        }

        maxx = 0;
        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < maxx && nums[i + 1] < nums[i]) {
                ans++;
            }
            maxx = max(maxx, nums[i + 1]);
        }

        return ans;
    }
};