class Solution {
public:
    vector<vector<string>> ans;
    
    bool can(int r, int c, int n, vector<string> &res){
        for(int i=0; i<c; i++){
            if(res[r][i]=='Q') return false;
        }
        for(int i=1; c-i>=0 && r-i>=0; i++){
            if(res[r-i][c-i]=='Q') return false;
        }
        for(int i=1; c-i>=0 && r+i<n; i++){
            if(res[r+i][c-i]=='Q') return false;
        }
        return true;
    }
    
    void rec(int col, int n, vector<string> &res){
        if(col==n){
            ans.push_back(res);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(can(row,col,n,res)){
                res[row][col]='Q';
                rec(col+1,n,res);
                res[row][col]='.';
            }    
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> res(n,string(n,'.'));
        rec(0,n,res);
        return ans;
    }  
};