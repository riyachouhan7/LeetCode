class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            maxh.push({abs(x-arr[i]),arr[i]});
            if(maxh.size()>k)
            {
                maxh.pop();
            }
        }
        vector<int> v;
        while(maxh.size()>0)
        {
            v.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};