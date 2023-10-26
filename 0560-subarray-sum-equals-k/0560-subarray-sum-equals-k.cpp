class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[sum]++;
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()) 
                ans+=m[sum-k];
        }
        return ans;
    }
};