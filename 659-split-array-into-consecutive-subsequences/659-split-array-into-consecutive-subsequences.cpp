class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int,int> availability_map;
        unordered_map<int,int> vacancy_map;
        
        for(auto i : nums)
            availability_map[i]++;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {            
            if(availability_map[nums[i]] <= 0)
                continue;
            else if(vacancy_map[nums[i]] > 0)
            {
                availability_map[nums[i]]--;
                vacancy_map[nums[i]]--;
                vacancy_map[nums[i] + 1]++;              
            }
            else if(availability_map[nums[i]] > 0 && availability_map[nums[i] + 1] > 0 && availability_map[nums[i] + 2] > 0)
            {
                availability_map[nums[i]]--;
                availability_map[nums[i] + 1]--; 
                availability_map[nums[i] + 2]--; 
                vacancy_map[nums[i] + 3]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};