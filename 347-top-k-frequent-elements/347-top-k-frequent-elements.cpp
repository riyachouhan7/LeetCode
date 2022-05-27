class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minh;
        unordered_map <int,int> ump;
        vector <int> v;
        int n=nums.size();
        
        for(int i=0; i<n; i++)
            ump[nums[i]]++;
        
        for(auto i=ump.begin(); i!=ump.end(); i++)
        {
            minh.push({i->second, i->first});
            if(minh.size() > k)
                minh.pop();
        }
        
        while(minh.size() > 0)
        {
            v.push_back(minh.top().second);
            minh.pop();
        }
        
        return v;
    }
};