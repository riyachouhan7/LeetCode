class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        
        for(auto x : s)
        {
            v[x - 'a']++;
        }
        
        sort(v.begin(),v.end(),greater<int>());
        
        int maxFrequency = v[0];
        int ans=0;
        for(auto x : v)
        {
            if(x > maxFrequency)
            {
                if(maxFrequency > 0)
                    ans += x - maxFrequency;
                else
                    ans += x;
            }
            maxFrequency = min(maxFrequency-1, x-1);
        }
        return ans;
    }
};