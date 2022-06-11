class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        int count = 0;
        if(nums.size() < 3) return 0;
    
        sort(nums.begin(), nums.end());
    
        for(int i=2; i<nums.size() ; i++)
        {
            int left = 0, right = i-1; 
        
            while(left < right)
            {
                if(nums[left] + nums[right] > nums[i])
                {
                    count += right - left;
                    right--;
                }
                else
                    left++;
            }
         }
         return count;
    }   
};