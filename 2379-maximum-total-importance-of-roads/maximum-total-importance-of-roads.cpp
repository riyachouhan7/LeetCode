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
        long long sum=0;
        vector<int>indegree(n,0);
        for(int i=0;i<roads.size();i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        vector<int>val(n);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({indegree[i],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int k=n;
        for(int i=0;i<n;i++)
        {
           int node=v[i].second;
           val[node]=k;
           k--;
        }
        for(int i=0;i<roads.size();i++){
            sum=sum+val[roads[i][0]]+val[roads[i][1]];
        }
        return sum;
    }
};