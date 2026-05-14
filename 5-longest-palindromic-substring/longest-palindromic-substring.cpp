class Solution {
public:

    vector<vector<int>> dp;
    bool solve(int i, int j, string &s)
    {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) 
        {
            return dp[i][j] = solve(i+1, j-1, s);
        }
        return dp[i][j] = 0;
    }

    
    string longestPalindrome(string &s) {
        int n = s.size();
        int maxlen = 0;
        int sp = 0;

        dp = vector<vector<int>>(n, vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(solve(i, j, s)) {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};