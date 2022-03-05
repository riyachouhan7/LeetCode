class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int target=-1;
        int max_count=0;
        for(int i =0;i<nums.size();i++)
        {
            int count=0;
            if(nums[i]==key)
            {
                for(int j=i+1;j<nums.size();j++)
                { 
                    if(nums[j]==nums[i+1])
                     count++;
                }
                if(max_count<count)
                {   max_count=count;
                    target=nums[i+1];
                }            
            }
                
        }
        return target;
    }
};