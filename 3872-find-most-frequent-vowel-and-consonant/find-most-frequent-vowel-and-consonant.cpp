class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        int vow = 0,cons = 0;
        unordered_map<int,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(char i='a';i<='z';i++){
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'){
                vow = max(vow, mp[i]);
            }
            else{
                cons = max(cons, mp[i]);
            }
        }

        return vow+cons;
    }
};