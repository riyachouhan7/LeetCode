class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>m;
        for(auto x : magazine){
            m[x]++;
        }
        for(auto y : ransomNote){
            if(m[y]==0) return false;
            m[y]--;
        }
        return true;  
    }
};