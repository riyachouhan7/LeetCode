class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> v1;
        
        for(int i=1;i<=searchWord.size();i++)
        {
            string s1=searchWord.substr(0,i);
            int count=0;
            vector<string> v2;
            for(int j=0;j<products.size();j++)
            {
                string s2=products[j].substr(0,i);
                if(s1==s2){
                     v2.push_back(products[j]);
                     count++; 
                }
                if(count==3) 
                    break;
            }
            v1.push_back(v2);
        }
        return v1;
    }
};