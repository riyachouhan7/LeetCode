class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector <int> res;
        int n1=nums1.size();
        int n2=nums2.size();
        int i=n1,j=n2;
        while(i>0 && j>0){
            int a=nums1[i-1];
            int b=nums2[j-1];
            if(a==b){
                res.push_back(a);
                i--;
                j--;
            }
            else if(a>b){
                i--;
            }
            else
                j--;
        }
        return res;
    }
};