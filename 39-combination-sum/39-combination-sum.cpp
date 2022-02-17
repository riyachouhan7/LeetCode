class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>& c,int t,vector<int>&sol){
        if(t==0){
            ans.push_back(sol);
            return;
        }
        if(t<0){
            return;
        }
        if(i==c.size()){
            return;
        }
        solve(i+1,c,t,sol);
        sol.push_back(c[i]);
        solve(i,c,t-c[i],sol);
        sol.pop_back();
    }
    vector<vector<int>>combinationSum(vector<int>& c,int t){
        vector<int> sol;
        solve(0,c,t,sol);
        return ans;
    }
};