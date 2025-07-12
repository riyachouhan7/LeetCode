class Solution {
public:
    int rows, cols;
    int maxSide;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<char>>& matrix) {
        if (i >= rows || j >= cols) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min({dfs(i+1, j, matrix), dfs(i, j+1, matrix), dfs(i+1, j+1, matrix)});
            maxSide = max(maxSide, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        maxSide = 0;
        dp.assign(rows, vector<int>(cols, -1)); // initialize memoization table

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(i, j, matrix);
            }
        }
        
        return maxSide * maxSide;
    }
};