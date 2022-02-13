class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> result={{}};
        vector<int> current;
        int size;
        for (auto num : nums){
            size=result.size();
            for (int i=0;i<size;i++){
                current=result[i];
                current.push_back(num);
                if(find(result.begin(),result.end(),current)==result.end())
                    result.push_back(current);
            }
        }
        return result;
    }
};