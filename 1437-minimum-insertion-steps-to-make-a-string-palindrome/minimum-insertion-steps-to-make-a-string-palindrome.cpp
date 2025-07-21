class Solution {
public:
    int help(int i, int j, string &s, vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];
        
        else if(s[i]==s[j]) return help(i+1, j-1, s, dp);
        
        else {
            int take1 = help(i+1, j, s, dp);
            int take2 = help(i, j-1, s, dp);

            return dp[i][j]= 1 + min(take1, take2);
        }
    }
    int minInsertions(string s) 
    {
        int n= s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return help(0, n-1, s, dp);
    }
};