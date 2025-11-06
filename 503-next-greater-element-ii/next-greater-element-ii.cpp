class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        // Traverse the array twice
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            while (!st.empty() && nums[idx] > nums[st.top()]) {
                result[st.top()] = nums[idx];
                st.pop();
            }

            // Only push indexes from first pass
            if (i < n) st.push(idx);
        }

        return result;
    }
};