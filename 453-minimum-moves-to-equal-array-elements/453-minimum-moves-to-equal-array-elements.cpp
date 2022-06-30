class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>0;i--)
        {
            count+=nums[i]-nums[0];
        }
        return count;
    }
};