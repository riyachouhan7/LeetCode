class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (char c : s) {
            int val = c - 'a';              // map 'a'→0, 'b'→1, ... 'z'→25
            int steps = (26 - val) % 26;    // steps needed to reach 'a'
            ans = max(ans, steps);
        }
        return ans;
    }
};
