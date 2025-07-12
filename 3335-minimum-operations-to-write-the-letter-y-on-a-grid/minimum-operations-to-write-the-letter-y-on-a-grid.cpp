class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countY = 0, countNonY = 0;
        vector<int> freqY(10, 0), freqNonY(10, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool isY = false;
                if (i < m / 2) {
                    if (j == i || j == n - 1 - i) isY = true;
                } else {
                    if (j == n / 2) isY = true;
                }

                int digit = grid[i][j];
                if (isY) {
                    freqY[digit]++;
                    countY++;
                } else {
                    freqNonY[digit]++;
                    countNonY++;
                }
            }
        }

        int res = m * n;

        for (int d1 = 0; d1 <= 9; ++d1) {
            for (int d2 = 0; d2 <= 9; ++d2) {
                if (d1 == d2) continue;
                int repaintY = countY - freqY[d1];
                int repaintNonY = countNonY - freqNonY[d2];
                res = min(res, repaintY + repaintNonY);
            }
        }

        return res;
    }
};
