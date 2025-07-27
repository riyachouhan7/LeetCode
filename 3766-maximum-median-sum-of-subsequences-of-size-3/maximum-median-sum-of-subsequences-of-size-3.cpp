class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort in ascending order
        int n = nums.size();
        long long ans = 0;

        for (int i = n - 2; i >= n / 3; i -= 2) {
            ans += nums[i]; // Pick the median of each triplet
        }

        return ans;
    }
};

// class Solution {
// public:
//     int maxMediansSum(vector<int>& nums) {
//         sort(nums.rbegin(), nums.rend()); // Sort in descending order
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i += 3) {
//             sum += nums[i + 1]; // pick the second-largest (median)
//         }
//         return sum;
//     }
// };
