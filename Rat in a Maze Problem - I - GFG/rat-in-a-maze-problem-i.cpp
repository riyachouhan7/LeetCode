//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    bool isSafe(vector<vector<int>> &m,vector<vector<int>> &visited, int srcx, int srcy, int n)
    {
        if(srcx>=0 && srcy>=0 && srcx<n && srcy<n && m[srcx][srcy] == 1 && !visited[srcx][srcy])
        {
            return true;
        }
        return false;
    }
    
    void helper(vector<vector<int>> &m,vector<vector<int>> &visited, int n, int srcx, int srcy, string temp)
    {
        if(srcx == n-1 && srcy == n-1)
        {
            ans.push_back(temp);
            return;
        }
        visited[srcx][srcy] = 1;
        if(isSafe(m, visited, srcx+1, srcy, n))
        {
            helper(m, visited, n, srcx+1, srcy, temp+"D");
        }
        if(isSafe(m, visited, srcx, srcy-1, n))
        {
            helper(m, visited, n, srcx, srcy-1, temp+"L");
        }
        if(isSafe(m, visited, srcx, srcy+1, n))
        {
            helper(m, visited, n, srcx, srcy+1, temp+"R");
        }
        if(isSafe(m, visited, srcx-1, srcy, n))
        {
            helper(m, visited, n, srcx-1, srcy, temp+"U");
        }
        visited[srcx][srcy] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0) return ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        helper(m,visited,n,0,0,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends