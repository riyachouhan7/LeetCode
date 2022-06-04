class NumArray {
public:
    vector<int>sum;
    NumArray(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i==0)
                sum.push_back(nums[i]);
            else
                sum.push_back(nums[i] + sum[i - 1]);
        }
    }  
    int sumRange(int left, int right) {
        if(left==0)
            return sum[right];
        return sum[right] - sum[left - 1]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */