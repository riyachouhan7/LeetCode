class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, res = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!maxDeque.empty() && nums[right] > maxDeque.back())
                maxDeque.pop_back();
            while (!minDeque.empty() && nums[right] < minDeque.back())
                minDeque.pop_back();

            maxDeque.push_back(nums[right]);
            minDeque.push_back(nums[right]);

            while (!maxDeque.empty() && !minDeque.empty() &&
                   maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[left]) maxDeque.pop_front();
                if (minDeque.front() == nums[left]) minDeque.pop_front();
                ++left;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};