class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int ans = 0;
        int i=0, j=n-1;
        int water = 0;
        while(i<j)
        {
            water = min(height[j], height[i]);
            ans = max(ans, water * (j-i));
            if(height[i] < height[j])
            {
                i++;
            }
            else j--;
        }
        return ans;
    }
};