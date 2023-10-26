class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> map1(26,0);
        if (s.size() != t.size()) 
            return false;
        
        for(int i=0;i<s.size();i++)
        {
            map1[s[i]-'a']++;
            map1[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(map1[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};