class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        if(buckets == 1) return 0;
        
        int ans = 1;
        for(int i = 1; pow((minutesToTest / minutesToDie) + 1, i) < buckets; i++)
        {
            ans++;
        }
        return ans;
    }
};