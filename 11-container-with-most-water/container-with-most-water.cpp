class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int ans = 0; 
        int i = 0 ; 
        int j = height.size()-1; 
        int water = 0;

        while(i<j)
        {
            water = min(height[i],height[j]) * (j-i);
            ans  = max(water,ans);
            (height[i] < height[j]) ? i++ : j--;
        }
        return ans ; 
    }
};