class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int rst=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            if(sum>rst)rst=sum;
        }
        return rst;
    }
};