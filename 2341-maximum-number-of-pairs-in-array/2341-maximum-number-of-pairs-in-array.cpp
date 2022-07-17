class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums)
    {
        map<int,int>m;
        int size = nums.size();
        
        int countPairs=0,leftOvers=0;
        for(int i=0; i<size; i++)
        {
            m[nums[i]]++;
        }
        
        for(auto x : m)
        {
            countPairs += x.second/2;
            leftOvers += x.second%2;
        }
        return {countPairs,leftOvers};
    }
};