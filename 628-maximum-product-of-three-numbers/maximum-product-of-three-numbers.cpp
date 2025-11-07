class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        bool allNonNegative = (nums[0] >= 0);
        bool allNegative = (nums[n - 1] < 0);

        // Case 1: All numbers are non-negative or all are negative
        if (allNonNegative || allNegative) {
            // Just take the product of the three largest numbers
            return nums[n - 1] * nums[n - 2] * nums[n - 3];
        }

        // Case 2: Mixed signs — consider both possibilities
        int productUsingNegatives = nums[0] * nums[1] * nums[n - 1];     // two negatives + largest positive
        int productUsingPositives = nums[n - 3] * nums[n - 2] * nums[n - 1]; // three largest positives

        return max(productUsingNegatives, productUsingPositives);
    }
};
