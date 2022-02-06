class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int last=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                last=max(i,last);
                while(last<n && nums[last]==0)
                    last++;
                if(last==n)
                    return;
                swap(nums[i],nums[last]);
            }
        }
        return;
    }
};