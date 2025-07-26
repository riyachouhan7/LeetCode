class Solution {
public:
    int numDecodingsTopDown(string s, int index, vector<int>& dp) {
        if (index == s.length()) return 1;
        
        if (s[index] == '0') return 0;
        

        if (dp[index] != -1) return dp[index];
        

        int ways = numDecodingsTopDown(s, index + 1, dp);

        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
            ways += numDecodingsTopDown(s, index + 2, dp);
        }

        dp[index] = ways;
        return ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return numDecodingsTopDown(s, 0, dp);
    }
};