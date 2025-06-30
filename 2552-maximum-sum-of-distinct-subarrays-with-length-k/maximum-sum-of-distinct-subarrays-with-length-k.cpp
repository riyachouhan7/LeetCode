class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0, maxSum = 0;
        int i = 0, j = 0, n = nums.size();

        while (j < n) {
            freq[nums[j]]++;
            sum += nums[j];

            if (j - i + 1 < k) {
                j++;
            } 
            else if (j - i + 1 == k) {
                // Only consider this window if all elements are unique
                if (freq.size() == k) {
                    maxSum = max(maxSum, sum);
                }

                // Shrink the window
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
                j++;
            }
        }

        return maxSum;
    }
};

