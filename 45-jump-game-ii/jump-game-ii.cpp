class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int end = 0;
        int farthest = 0;

        for (int index = 0; index < nums.size() - 1; ++index) {
            farthest = max(farthest, index + nums[index]);

            if (index == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};
