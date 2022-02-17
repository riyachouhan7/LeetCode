class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int l=1,ml=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]){
                l++;
                ml=max(l,ml);
            }
            else if(nums[i-1]==nums[i])
                continue;
            else
                l=1;
        }
        return ml;
    }

};