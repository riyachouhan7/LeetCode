class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> best; // digitSum -> largest number
        int ans = -1;

        for (int num : nums) {
            int s = digitSum(num);
            if (best.count(s)) {
                ans = max(ans, best[s] + num); // try forming a pair
                best[s] = max(best[s], num);   // keep the larger one
            } else {
                best[s] = num;
            }
        }

        return ans;
    }
};
