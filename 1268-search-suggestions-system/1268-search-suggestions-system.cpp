class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>>res;
        sort(products.begin(),products.end());
        int n=products.size();
        for(int i=0;i<searchWord.size();i++)
        {
            string s=searchWord.substr(0,i+1);
            int low=0,temp=0,high=n-1;
            vector<string>ans;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(products[mid]>=s)
                {
                    temp=mid;
                    high=mid-1;
                }
                else
                {
                   low=mid+1;
                }
            }

            for(int j=temp;j<temp+3 and j<n;j++)
            {
                if(products[j].find(s)==0)
                    ans.push_back(products[j]);
                else
                    break;
            }
            res.push_back(ans);
        }
        return res;
        
    }
};