class Solution {
public:
    int helper(int ind, int buy, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(ind >= prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1)
        {
            return dp[ind][buy] = max(-prices[ind] + helper(ind+1, 0, prices, dp) , 0 + helper(ind+1, 1, prices, dp));
        }

        //for ind = n-1
        return dp[ind][buy] = max(prices[ind] + helper(ind+2, 1, prices, dp) , 0 + helper(ind+1, 0, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return helper(0, 1, prices, dp);
        
    }
};