class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int lsum = 0, rsum = 0, maxSum = 0;
        for(int i=0;i<k;i++)
        {
            lsum = lsum+cp[i];
            maxSum = lsum;
        }
        int ri = n-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum = lsum-cp[i];
            rsum = rsum+cp[ri];
            ri = ri-1;
            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};