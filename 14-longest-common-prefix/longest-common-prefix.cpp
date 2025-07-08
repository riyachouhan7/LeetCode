class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string l = strs[0], r = strs[n-1], ans="";
        for(int i=0;i<l.size();i++) {
            if(l[i] == r[i]) {
                ans += l[i];
            }
            else break;
        }
        return ans; 
    }
};