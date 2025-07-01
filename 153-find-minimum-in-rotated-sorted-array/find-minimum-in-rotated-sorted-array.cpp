class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = nums.size()-1;

        while(start <= end)
        {
            if(nums[start] < nums[end]) return nums[start];
            int mid = start + (end - start)/2;
            int prev = (mid+ n - 1) % n;
            int next = (mid + 1) % n;

            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];

            else if(nums[mid] < nums[start]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }   
        return -1;
    }
};