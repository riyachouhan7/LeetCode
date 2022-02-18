class Solution {
public:
    bool canJump(vector<int>& nums) {
     
      int n=nums.size();
      int p=0;
        for(int i=0;i<n;i++){   
            if(i>p)
                return false;
            p=max(p,i+nums[i]);
        }
        return true;
    }
};