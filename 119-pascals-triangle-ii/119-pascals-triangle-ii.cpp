class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        for(int i = 0; i<=rowIndex; i++)
        {
            vector<int> v(i+1, 1);
            for(int j = 1; j<i; j++)
            {
                v[j] = result[i - 1] [j] + result [i-1] [j-1];
            }
            result.push_back(v);
        }
        return result[rowIndex];
    }
};