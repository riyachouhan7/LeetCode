class Solution {
public:
    // using max heap
    int findKthLargest(vector<int>& nums, int k) {
	    priority_queue<int> maxh(nums.begin(),nums.end());
	    for(int i=1;i<k;i++) maxh.pop();
	    return maxh.top();
    }
};