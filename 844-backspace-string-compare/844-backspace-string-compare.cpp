class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a=s.size();
        int b=t.size();
        stack<char>s1;
        stack<char>s2;
        for(int i=0;i<a;i++)
        {
            if(s[i]=='#' && !s1.empty())
                s1.pop();
            else if(s[i]!='#')
                s1.push(s[i]);
        } 
        for(int i=0;i<b;i++)
        {
            if(t[i]=='#' && !s2.empty())
                s2.pop();
            else if(t[i]!='#' )
                s2.push(t[i]);
        }
        return s1==s2;
    }
};
