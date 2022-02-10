class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0, count=0;
        unordered_map<int, int>p;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum==k)
                count++;
            if(p.find(sum-k)!=p.end())
                count+=p[sum-k];
                p[sum]++;
            }  
        return count;
    }
};