class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        const int MOD = 1e9 + 7; 
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end()); 
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max1 = 0, max2 = 0; 
        
        int n = horizontalCuts.size(), m = verticalCuts.size();
        for(int i = 1; i<n; i++)
        {
            max1 = max(max1, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i = 1; i<m; i++)
        {
            max2 = max(max2, verticalCuts[i] - verticalCuts[i-1]);
        }
        return (long long)max1 * (long long)max2 % MOD;
        
    }
};