class Solution {
public:
    int function(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(i==prices.size() || cap==0)
            return 0;
        
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        
        int profit=0;
        
        if(buy==1)
        {
            profit= max(-prices[i]+function(i+1,0,cap,prices,dp),0+function(i+1,1,cap,prices,dp));
        }
        else
        {
            profit= max(prices[i]+function(i+1,1,cap-1,prices,dp),0+function(i+1,0,cap,prices,dp));
        }
        
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        
        /*for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=0;i<=k;cap++)
                {
                    if(buy==1)
                    {
                        dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
                    }
                    else
                    {
                        dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][k];*/
        return function(0,1,k,prices,dp);
        
    }
};