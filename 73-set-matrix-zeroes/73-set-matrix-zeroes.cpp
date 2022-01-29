class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        set<int> R,C;
        int rows=matrix.size();
        int columns=matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
                if(matrix[i][j]==0) R.insert(i),C.insert(j);
        }
        for(auto x:R)
            for(int i=0;i<columns;i++)
                matrix[x][i]=0;
        for(auto x:C)
            for(int i=0;i<rows;i++)
                matrix[i][x]=0;
    }
};