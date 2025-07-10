class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Check farthest from the right end
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, n - 1 - i);
                break; // since checking from left, this is the farthest possible
            }
        }

        // Check farthest from the left end
        for (int j = n - 1; j >= 0; --j) {
            if (colors[0] != colors[j]) {
                maxDist = max(maxDist, j);
                break; // since checking from right, this is the farthest possible
            }
        }

        return maxDist;
    }
};