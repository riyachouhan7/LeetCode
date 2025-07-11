class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> time(n);
        for(int i = 0; i < n; i++)
        {
            string ans = timePoints[i];
            int hourSubstr = stoi(ans.substr(0, 2));
            int minSubstr = stoi(ans.substr(3,2));

            time[i] = hourSubstr*60 + minSubstr;
        }

        sort(time.begin(), time.end());

        int minDiff = INT_MAX;
        for(int i=1; i<n; i++)
        {
            minDiff = min(minDiff, (time[i] - time[i-1]));
        }

        return min(minDiff, (24*60-time[n-1]+time[0]));
    }
};