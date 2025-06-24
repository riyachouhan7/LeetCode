class Solution {
public:
    int m, n;
    bool helper(int i,int j,vector<vector<char>>& board, string word,int ind){
        if(ind == word.size())
        {
            return true;
        }
        if(i<0 || j<0 || i==m || j==n || board[i][j]!=word[ind]) 
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';

        bool help1 = helper(i+1, j, board, word, ind+1);
        bool help2 = helper(i, j+1, board, word, ind+1);
        bool help3 = helper(i-1, j, board, word, ind+1);
        bool help4 = helper(i, j-1, board, word, ind+1);
        
        board[i][j] = temp;
        return help1 || help2 || help3 || help4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(helper(i,j,board,word,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};