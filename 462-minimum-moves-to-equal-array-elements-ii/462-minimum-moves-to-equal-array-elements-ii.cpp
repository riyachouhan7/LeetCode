class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int mid=n/2;
            count+=abs(nums[i]-nums[mid]);
        }
        return count;
    }
};