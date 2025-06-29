class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(128, 0);
        int maxFreq = 0, maxLen = 0, l = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            if ((r - l + 1) - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};