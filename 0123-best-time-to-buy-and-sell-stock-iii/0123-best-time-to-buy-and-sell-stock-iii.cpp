class Solution {
public:
    int function(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(i==prices.size())
            return 0;
        
        if(cap==0)
            return 0;
        
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        
        int profit=0;
        
        if(buy==1)
        {
            profit=max(-prices[i]+function(i+1,0,cap,prices,dp),0+function(i+1,1,cap,prices,dp));
        }
        else
        {
            profit=max(prices[i]+function(i+1,1,cap-1,prices,dp),0+function(i+1,0,cap,prices,dp));
        }
        
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return function(0,1,2,prices,dp);
    }
};