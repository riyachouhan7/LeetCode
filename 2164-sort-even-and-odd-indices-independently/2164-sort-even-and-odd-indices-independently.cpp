class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int> even, odd;
        for(int i=0;i<n;i++)
        {
            if(i%2) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        
        int i=0,j=0;
        
        vector<int> ans;
        
        while(i<odd.size() || j<even.size())
        {
            if(j<even.size())
            {
                ans.push_back(even[j++]);
            }
            if(i<odd.size())
            {
               ans.push_back(odd[i++]);
            }
        }
        return ans;  
    }
};