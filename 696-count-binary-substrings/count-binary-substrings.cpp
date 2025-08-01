class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int sum = 0;
        int prev = 0, curr = 1;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1])
            {
                curr++;
            }
            else
            {
                sum += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        sum += min(prev, curr);
        return sum;
    }
};