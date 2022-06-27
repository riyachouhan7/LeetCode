class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(char c : n)
        {
            int curr = c - 48;
            ans = max(ans, curr);
        }
        return ans;
    }
};