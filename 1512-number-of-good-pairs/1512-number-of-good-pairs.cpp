class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n=nums.size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                count=count+mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        
        return count;
    }
};