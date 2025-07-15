class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s) {
        if (i >= j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1, s);
        return dp[i][j] = 0;
    }

    string longestPalindrome(string &s) {
        int n = s.length();
        int maxLen = 0;
        int startingPoint = 0;

        dp = vector<vector<int>>(n, vector<int>(n, -1));  //Properly initialize class-level dp

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(i, j, s)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        startingPoint = i;
                    }
                }
            }
        }

        return s.substr(startingPoint, maxLen);
    }
};
