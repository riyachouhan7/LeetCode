class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int,int> freq;
        for(int i : arr)
        {
            freq[i]++;
        }
        
        vector<int> v;
        for(auto it : freq)
        {
            v.push_back(it.second);
        }
        
        sort(v.begin(),v.end(),greater<int>());
        int ans = 0;
        int k = 0;
        while(arr.size()/2 > k)
        {
            k += v[ans++];
        }
        
        return ans;
    }
};