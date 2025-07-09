class Solution {
public:
    int helper(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(i == prices.size() || cap == 0) return 0;
        
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        
        int profit = 0;
        
        if(buy == 1) {
            profit = max(-prices[i] + helper(i+1, 0, cap, prices, dp), 0 + helper(i+1, 1, cap, prices, dp));
        }
        else {
            profit = max(prices[i] + helper(i+1, 1, cap-1, prices, dp), 0 + helper(i+1, 0, cap, prices, dp));
        }
        
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return helper(0, 1, k, prices, dp);
        
    }
};