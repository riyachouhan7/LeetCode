class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            mid = l + (r-l)/2;
          
            if(nums[mid] > nums[r]) { //something wrong on right side. Possibly my answer lies in right side.
                l = mid+1;            //move right (Discarding mid, because it's greater than nums[r], so it can't be the minimum element)
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};