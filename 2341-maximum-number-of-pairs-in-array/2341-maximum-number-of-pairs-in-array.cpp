class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums)
    {
        map<int,int>m;
        int size = nums.size();
        
        vector<int> v(2,0);
        for(int i=0; i<size; i++)
        {
            m[nums[i]]++;
        }
        
        for(auto x : m)
        {
            v[0] += x.second/2;
            v[1] += x.second%2;
        }
        return v;
    }
};