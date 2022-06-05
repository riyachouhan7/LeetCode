class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        while(n>1)
        {
            vector<int> new1;
            for(int i=0;i<n;i+=2)
            {
                int a=nums[i];
                int b=nums[i+1];
                int k;
                if(k%2==0)
                {
                    new1.push_back(min(a,b));
                    k++;
                }
                else
                {
                    new1.push_back(max(a,b));
                    k--;
                }
            }
            nums=new1;
            n=nums.size();
        }
        return nums[0];
    }
};