class Solution {
public:
    
    vector<vector<int>> result;
    vector<int> pairs;
    map<int,bool> flag;
    int n;
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        n=nums.size();
        solve(nums);
        return result;
        
    }
    
    void solve(vector<int> &nums)
    {
        if(pairs.size()==n) 
            result.push_back(pairs);
        
        else
        {
            for(int i=0;i<n;i++)
            {
                if(!flag[nums[i]])
                {
                    pairs.push_back(nums[i]);
                    flag[nums[i]]=true;
                    solve(nums);
                    pairs.pop_back();
                    flag[nums[i]]=false;
                }
            }
        }
    }
    
};