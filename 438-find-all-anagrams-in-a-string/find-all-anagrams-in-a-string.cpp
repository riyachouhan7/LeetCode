class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char , int> mp;
        //taking freq of element of s1
        for(auto it: p) mp[it]++;
        vector<int> ans;
        int zeroCount = mp.size();
        int i = 0; 
        int j = 0;
        int k = p.size();
        //standard question of fixed size sliding window 
        while(j < s.size()){
            //doing calculation 
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) zeroCount--;
            }
             //when we don't hit the window
            if(j-i+1 < k) j++;
             //when hit the window
            else if(j-i+1 == k){
                if(zeroCount == 0) ans.push_back(i);
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
                        zeroCount++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};