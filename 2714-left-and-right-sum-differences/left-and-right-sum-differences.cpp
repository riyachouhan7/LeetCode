class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, total = 0;
        vector<int> ans(n);

        for(int i=0;i<n;i++) {
            total += nums[i];
        }

        for(int i=0;i<n;i++)
        {
            right = total-left-nums[i];
            ans[i] = abs(right - left);
            left += nums[i];
        }
        return ans;
    }
};