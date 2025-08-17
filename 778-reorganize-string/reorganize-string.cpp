class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        int n = s.size();
        
        vector<int> count(26, 0);
        for(char& ch: s)
        {
            count[ch-'a']++;
            if( count[ch-'a'] > (n+1)/2)
            {
                return "";
            }
        }

        priority_queue<P> pq;
        for(char ch ='a'; ch <= 'z'; ch++)
        {
            if(count[ch-'a']>0)
            {
                pq.push({count[ch-'a'], ch});
            }
        }
        string result = "";
        while(pq.size()>=2)
        {
            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            result.push_back(p1.second); p1.first--;
            result.push_back(p2.second); p2.first--;

            if(p1.first>0)
            {
                pq.push(p1);
            }
             if(p2.first>0)
            {
                pq.push(p2);
            }
        }

        if(!pq.empty())
        {
            result.push_back(pq.top().second);
        }
        return result;
    }
};