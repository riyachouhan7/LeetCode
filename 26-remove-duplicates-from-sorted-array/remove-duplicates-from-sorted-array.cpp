class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> res;

        if(nums.empty()) return 0;

        res.push_back(nums[0]);

        for(int i=1;i<n;i++) {
            if(nums[i] != nums[i-1])
            {   
                res.push_back(nums[i]);
            }
        }

        nums = res;
        return res.size();
    }
};