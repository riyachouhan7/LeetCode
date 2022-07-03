class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        char k='a';
        for(int i=0;i<key.size();i++)
        {
            if(key[i]==' ')
                continue;
            else
            {
                if(mp.find(key[i])==mp.end())
                {
                    mp[key[i]]=k;
                    k=k+1;
                }
            }
        }
        string ans="";
        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
                ans+=" ";
            else
            {
                ans+=mp[message[i]];
            }
        }
        return ans;
    }
};