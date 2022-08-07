class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            long long count=0;
            if(nums[i] == 0)
            {
                while(i<nums.size() && nums[i]==0)
                {
                    count++;
                    i++;
                }
                ans += count*(count+1)/2;
            }
        }
        return ans;
    }
};