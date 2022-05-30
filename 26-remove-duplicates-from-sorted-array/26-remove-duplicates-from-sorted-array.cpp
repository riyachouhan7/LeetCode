class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        set <int> s;
        for(int i=0; i<n; i++)
            s.insert(nums[i]);
        
        int ans = s.size();
        int i=0;
        for(auto x:s){
            nums[i]=x;
            i++;
        }
        return ans;
    }
};