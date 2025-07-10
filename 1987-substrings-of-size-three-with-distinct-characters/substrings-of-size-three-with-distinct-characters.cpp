class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if(s.size() < 3) return 0;
        int count = 0;
        for(int i = 0; i <= n-3; i++){

            if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]){
                count++;
            }
        }
        return count; 
    }
};