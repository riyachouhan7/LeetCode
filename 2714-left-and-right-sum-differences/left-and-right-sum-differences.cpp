class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1(n,0);
        vector<int> v2(n,0);

        int sum1 = 0, sum2 = 0;
        for(int i=1;i<n;i++)
        {
            sum1 += nums[i-1];
            v1.push_back(sum1);
            v1[i] = sum1;            
        }


        for(int i=n-2;i>=0;i--)
        {
            sum2 += nums[i+1];
            v2.push_back(sum2);
            v2[i] = sum2;
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i] = abs(v1[i] - v2[i]);
        }
        return ans;
    }
};