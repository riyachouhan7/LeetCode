class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int>hash(128, -1);
        int i = 0, j = 0, maxlen = 0;
        int n = s.size();

        while(j < n){ 
            if(hash[s[i]] != -1 && hash[s[j]] >= i) { 
                i = hash[s[j]] + 1;
            }
            maxlen=max(maxlen, j-i+1);
            hash[s[j]] = j;
            j++;
        }
        return maxlen;
    }
};