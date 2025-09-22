class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxFreq = 0;
        for(auto it : nums)
        {
            mp[it]++;
            maxFreq = max(maxFreq, mp[it]);
        }
        int ans = 0;
        for(auto it: mp)
        {
            if(it.second == maxFreq)
            {
                ans+=maxFreq;
            }
        }
        return ans;
    }
};