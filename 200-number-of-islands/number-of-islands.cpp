class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j,int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || grid[i][j]=='$')
        {
            return;
        }
        grid[i][j] = '$';
        helper(grid,i+1,j,n,m);
        helper(grid,i-1,j,n,m);
        helper(grid,i,j+1,n,m);
        helper(grid,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) 
    {  
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    helper(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};