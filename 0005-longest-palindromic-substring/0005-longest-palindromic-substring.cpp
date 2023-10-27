class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int m=INT_MIN;
        string ans;
        for(int d=0;d<n;d++)
        {
            for(int i=0,j=i+d;j<n;j++,i++)
            {
                if(i==j)
                dp[i][j]=1;
                else if(d==1)
                {
                    if(s[i]==s[j])
                    dp[i][j]=2;
                    else
                    dp[i][j]=0;
                }
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1])
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                if(dp[i][j])
                {
                    if(j-i+1>m)
                    {
                        m=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;

    }
};