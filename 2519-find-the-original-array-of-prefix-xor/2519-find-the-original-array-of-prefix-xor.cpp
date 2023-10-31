class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int size = pref.size();
        vector<int> ans;
        ans.push_back(pref[0]);
        for(int i = 1; i < size; i++)
        {
            ans.push_back(pref[i]^pref[i-1]);
        }
        return ans;
    }
};