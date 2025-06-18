class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>st;
        for(char ch : s)
        {
            if(!st.empty() && st.top().first == ch)
            {
                st.top().second++;
                if(st.top().second == k)
                {
                    st.pop();
                }
            } 
            else
            {
                st.push({ch, 1});
            }
        }
        
        string str;
        while(!st.empty())
        {
            str += string(st.top().second,st.top().first);
            st.pop();
        }
        
        reverse(str.begin(),str.end());
        return str;
    }
};