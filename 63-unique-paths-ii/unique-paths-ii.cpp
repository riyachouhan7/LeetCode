class Solution {
public:
    // int mod = (int)(1e9+7);
    // int help(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
    //     if(i>=0 && j>=0 && grid[i][j]==1) return 0;
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up = help(i-1, j,grid, dp);
    //     int left = help(i,j-1,grid,dp);
    //     return dp[i][j] = (up+left)%mod;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return help(m-1,n-1,grid,dp);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left; 
                }
            }
        }
        return dp[m-1][n-1];
    }
};