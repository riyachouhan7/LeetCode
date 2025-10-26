class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make sure mid is even (so pairs are [mid, mid+1])
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Pair is proper, single element is to the right
                low = mid + 2;
            } else {
                // Pair is broken, single element is to the left (or mid itself)
                high = mid;
            }
        }

        return nums[low];
    }
};
