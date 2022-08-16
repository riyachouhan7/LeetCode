class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            int val = nums[i];
            int l = i+1;
            int r = size-1;
            while(l<r)
            {
                int currSum = val+nums[l]+nums[r];
                if(currSum == 0)
                {
                    s.insert({val,nums[l++],nums[r--]});
                }
                else if(currSum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};