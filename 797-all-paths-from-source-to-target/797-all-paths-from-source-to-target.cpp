class Solution {
public:
    void helper(vector<vector<int>>&graph, int node, vector<int>&path, vector<vector<int>>&ans){
        path.push_back(node); 
        for(int x: graph[node]){
            if(x == graph.size()-1){ 
                path.push_back(x);  
                ans.push_back(path);
                path.pop_back(); 
            }
            helper(graph,x,path,ans);
            path.pop_back(); 
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(graph,0,path,ans);
        return ans;
    }
};