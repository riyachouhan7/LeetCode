class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                        count++;
                    }
                }
            }
        }
        return count;
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]!=nums[i+1])
        //         count++;
        // }
        // return count;
    }
};