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
        
        int oddj=0,eveni=0;
        int i=0;
        while(oddj<odd.size() || eveni<even.size())
        {
            if(eveni<even.size())
            {
                nums[i]=even[eveni];
                eveni++;
                i++;
            }
            if(oddj<odd.size())
            {
                nums[i]=odd[oddj];
                oddj++;
                i++;
            }
        }
        return nums;  
    }
};