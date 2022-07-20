class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int size = words.size();
        
        map<char,vector<int>> m;
         
        int index=0;
        for(auto it : s)
        {
            m[it].push_back(index++);
        }
        int count=0;
        for(int i=0;i<size;i++)
        {
            string curr = words[i];
            
            int newIndex = -1;
            for(int j=0;j<curr.size();j++)
            {
                auto x = upper_bound(m[curr[j]].begin(),m[curr[j]].end(),newIndex);
                if(x == m[curr[j]].end()) 
                    break;
                newIndex = *x;
                
                if(j == curr.size()-1)
                    count++;
            }
        }
        return count;
    }
};