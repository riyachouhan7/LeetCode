class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(nums[i] > sum) sum=nums[i];
        ans = max(sum,ans);
    }
    return ans;
  }
};