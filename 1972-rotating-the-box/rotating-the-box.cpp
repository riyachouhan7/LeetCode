class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> result(n, vector<char>(m));
        // transpose
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                result[i][j] = boxGrid[j][i];
            }
        }

        // for 90 degree - reverse all row
        for(vector<char>& row : result)
        {
            reverse(row.begin(), row.end());
        }

        // gravity

        for(int j=0;j<m;j++)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(result[i][j] == '.')
                {
                    int stoneRow = -1;
                    for(int k=i-1;k>=0;k--)
                    {
                        if(result[k][j] == '*')
                        {
                            break;
                        }
                        else if(result[k][j] == '#')
                        {
                            stoneRow = k;
                            break;
                        }
                    }
                    if(stoneRow != -1)
                    {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }
        return result;
    }
};