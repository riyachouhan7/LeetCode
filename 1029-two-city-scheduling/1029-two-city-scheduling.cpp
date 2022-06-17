class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(),sum=0;
        sort(costs.begin(),costs.end(),relativecosts);
        for(int i=0;i<n/2;i++)
            sum+=costs[i][0];
        for(int i=n/2;i<n;i++)
            sum+=costs[i][1];
        
        return sum;
    }
    
    static bool relativecosts (vector<int> &first,vector<int>&second)
    {
        return first[1]-first[0]>second[1]-second[0];
    }
    
};