// class Solution {
// public:
//     long long maximumImportance(int n, vector<vector<int>>& roads) {
//         vector<int>ans;
//         int finalAns = 0;
//         int size = roads.size();
//         for(int i = 0;i<size;i++)
//         {
//             ans.push_back(roads[i][0]);
//             ans.push_back(roads[i][1]);
//         }
//         unordered_map<int, int> mp;
//         for(auto it: ans)
//         {
//             mp[it]++;
//         }
//         vector<int> res;
//         sort(ans.begin(),ans.end());
//         for(int i=ans.size();i>=1;i--)
//         {
//             res[ans.size()-1] = n;
//             n--;
//             finalAns+=res[i];
//         }
//         return finalAns;
//     }
// };

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(auto edge: roads){
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
        }
        sort(degree.begin(),degree.end());
        long long val = 1;
        long long ans=0;
        for(auto deg : degree)
        {
            ans += deg * val;
            val++;
        }
        return ans;
    }
};