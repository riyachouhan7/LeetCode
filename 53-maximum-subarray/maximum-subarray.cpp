class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = INT_MIN;

        for(int i=0;i<n;i++) {
            ans+=nums[i];
            sum = max(sum, ans);
            if(ans < 0) {
                ans = 0;
            }
        }
        return sum;
    }
};