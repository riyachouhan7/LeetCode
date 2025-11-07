class Solution {
public:
    bool isPossible(const vector<int>& nums, int maxOps, int mid) {
        int totalOps = 0;
        for (int num : nums) {
            totalOps += (num - 1) / mid;  // Number of splits needed
            if (totalOps > maxOps) return false;  // Early stop if already exceeding
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int result = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, maxOperations, mid)) {
                result = mid;      // Possible → try smaller penalty
                r = mid - 1;
            } else {
                l = mid + 1;       // Not possible → increase penalty
            }
        }

        return result;
    }
};