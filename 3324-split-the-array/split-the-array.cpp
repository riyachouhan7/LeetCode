class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num : nums)
        {
            freq[num]++;
            if(freq[num] > 2) 
            {
                return false;
            }
        }
        return true;
    }
};