class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        long long n = spells.size(), m = potions.size(), count=0;
        vector<int> ans;
        int size = potions.size();
        sort(potions.begin(),potions.end());
        for(long long i : spells)
        {
            int start = 0;
            int end = size - 1;
            int count = 0;
            while(start <= end)
            {
                int mid = start + (end - start) / 2;
                if(i*potions[mid] >= success)
                {
                    count += end - mid + 1;
                    end = mid - 1;
                }
                else if(i*potions[mid] < success)
                {
                    start = mid + 1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};