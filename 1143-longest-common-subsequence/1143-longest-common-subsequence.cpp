class Solution {
public:
    int t[1001][1001];
    
    int longestCommonSubsequence(string &text1, string &text2, int size1, int size2)
    {
        if(size1 == 0 || size2 == 0)
        {
            return 0;
        }
        
        if(t[size1][size2] != -1)
        {
            return t[size1][size2];
        }
        
        if(text1[size1-1] == text2[size2-1])
        {
            return t[size1][size2] = 1 + longestCommonSubsequence(text1, text2, size1-1,size2-1);
        }
        else
        {
            return t[size1][size2] = max(longestCommonSubsequence(text1, text2, size1-1,size2) ,longestCommonSubsequence(text1, text2, size1,size2-1));
        }
    }
    
    int longestCommonSubsequence(string &text1, string &text2)
    {
        int size1 = text1.size();
        int size2 = text2.size();
        
        memset(t, -1, sizeof(t));
        
        return longestCommonSubsequence(text1, text2, size1,size2);
    }
};