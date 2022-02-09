class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<pair<int,int>> s;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int diff = abs(nums[i]-nums[j]);
                if(diff == k)
                    s.insert({nums[i], nums[j]});
                else if(diff > k)
                    break;
                else
                    continue;
            }
        }
        return s.size();
    }
};