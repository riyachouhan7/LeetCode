class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int dp[n+1][2];
        dp[n][1]=dp[n][0]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    int a = -prices[i]+ dp[i+1][0];
                    int b = dp[i+1][1];

                    dp[i][j]= max(a,b);
                }
                else{
                    int a = prices[i]+ dp[i+1][1];
                    int b = dp[i+1][0];

                    dp[i][j]= max(a,b);
                }
            }
        }
        return dp[0][1];
    }
};