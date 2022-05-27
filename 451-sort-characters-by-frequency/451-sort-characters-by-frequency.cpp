class Solution {
public:
     string frequencySort(string s) 
    {
        unordered_map<int,int> ump;
        priority_queue<pair<int,char>> maxh;
        for(char i : s)
            ump[i]++;   //create a frequency map of character
        string ans;
        for(auto i : ump)
            maxh.push({i.second,i.first});  
        while(!maxh.empty())
        {
            auto i = maxh.top();
            for(int j=0;j<i.first;j++)
            ans += i.second;         
            maxh.pop();                 
        }
        return ans;
    }
};