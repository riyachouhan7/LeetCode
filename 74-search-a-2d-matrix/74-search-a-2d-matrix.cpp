class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int l=0,r=n-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(mat[i][mid]==target)
                    return true;
                else if(mat[i][mid]>target)
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return false;
    }
};