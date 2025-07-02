class Solution {
public:
    int numTrees(int n, vector<int> & dp) {

        if (n <= 1) return 1;
        // if subProblem is not solved
        if (!dp[n])
        {
            for (int i = 1; i <= n; i++)
            {
                dp[n] += numTrees(i - 1, dp) * numTrees(n - i, dp);
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        vector<int> dp(20);
        return numTrees(n, dp);
    }
};