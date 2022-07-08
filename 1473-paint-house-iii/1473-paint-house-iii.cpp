class Solution {
public:
    int dp[105][25][105];
    int solve(int i, int col, int target, vector<int>& houses, vector<vector<int>>& cost, int m, int n)
    {
        if(target<0)
            return 9999999;
        
        if(i==m)
        {
            if(target==0)
                return 0;
            else
                return 9999999;
        }
        
        if(dp[i][col][target]!=-1)
            return dp[i][col][target];
        
        if(houses[i]!=0)
        {
            if(col==houses[i])
                return solve(i+1, houses[i], target, houses, cost, m, n);
            else
                return solve(i+1, houses[i], target-1, houses, cost, m, n);
        }
            
        int a=INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(col==j+1)
                a = min(a, cost[i][j]+solve(i+1, col, target, houses, cost, m, n));
            else
                a = min(a, cost[i][j]+solve(i+1, j+1, target-1, houses, cost, m, n));
        }
        
        return dp[i][col][target]=a;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, target, houses, cost, m, n);
        if(ans >= 9999999)
            return -1;
        
        return ans;
    }
};