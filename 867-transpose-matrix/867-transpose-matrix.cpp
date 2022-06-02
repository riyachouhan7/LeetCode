class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> output;
        vector<int>input(row);
        
        for(int i = 0; i < col; i++){        
            for(int j = 0; j <row; j++){
               input[j] = matrix[j][i]; 
            }
            output.push_back(input);
        }
        return output;
    }
};