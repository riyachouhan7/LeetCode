class Solution {
public:
    int help(vector<int>nums) 
    {
        int size = nums.size();
        if(size < 1)
        {
            return 0;
        }
        if(size == 1)
        {
            return nums[0];
        }
        
        vector<int>dp(size,0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<size;i++)
        {
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums)
    {
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        if(size == 1)
        {
            return nums[0];
        }
        return max(help(vector<int>(nums.begin(),nums.end()-1)),help(vector<int>(nums.begin()+1,nums.end())));
    }
};