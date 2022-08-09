class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int size = arr.size();
        map<int, long long int> mp;
        sort(arr.begin(),arr.end());
        
        for(int k = 0;k<size;k++)
        {
            mp.insert({arr[k],1});
        }
        
        for(int i=1;i<size;i++)
        {
            auto it1 = mp.find(arr[i]);
            long long int count = 0;
            for(int j=0;j<i;j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    auto it2 = mp.find(arr[i]/arr[j]);
                    auto it3 = mp.find(arr[j]);
                    if(it2 != mp.end())
                    {
                        count += (it2->second)*(it3->second);
                    }
                }
            }
            it1->second += count;
        }
        long long int sum = 0;
        for(auto it4 = mp.begin(); it4 != mp.end();it4++)
        {
            sum += it4->second;
        }
        return sum % 1000000007;
    }
};