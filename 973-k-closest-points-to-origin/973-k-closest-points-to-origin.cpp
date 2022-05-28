class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        
        int n = points.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++)
        {
        maxh.push({(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
            while(maxh.size()>k)
            maxh.pop(); 
        }
        
        while(maxh.size()>0){
        pair<int,int> p = maxh.top().second; 
        v.push_back({p.first,p.second});
        maxh.pop();
        }
        return v;
    }
};