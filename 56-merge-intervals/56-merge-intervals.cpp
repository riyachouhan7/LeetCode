class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1)
            return intervals;
        sort(intervals.begin(),intervals.end()); 
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            for(int j=i+1;j<n;j++){
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(b>=c){ 
                    b=max(b,d);
                    i=j;
                }
            } 
            res.push_back({a,b});
        }
        return res;
    }
};