

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]+diff] && mp[nums[i]+2*diff])
                ans++;
        } 
        return ans;
    }
};