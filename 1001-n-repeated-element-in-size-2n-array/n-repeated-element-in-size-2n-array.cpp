class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++)
        {
            mp[nums[i]]++;
        }
        int n = size/2;
        for(auto it: mp)
        {
            if(it.second == n)
            {
                return it.first;
            }
        }
        return -1;
    }
};