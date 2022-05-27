class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>heap(nums.begin(),nums.end());
        int i=0;
        while (!heap.empty()){
            nums[i]=heap.top();
            heap.pop();
            i++;
        }
        return nums;
        
    }
};