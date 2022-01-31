class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>f(3);
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<=2;i++){
            for(int j=0;j<f[i];j++)
                ans.push_back(i);
        }
        nums=ans;
    }
};