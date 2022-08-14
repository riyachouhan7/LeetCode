class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        long long int size = edges.size();
        
        map<long long int,long long int> freq;
        for(long long int i=0;i<size;i++)
        {
            freq[edges[i]] += i;
        }
        long long int ans = INT_MIN;
        long long int k;
        for(auto it : freq)
        {
            if(ans < it.second)
            {
                ans = it.second;
                k = it.first;
            }
            //k = it.first;
        }
        return k;
    }
};