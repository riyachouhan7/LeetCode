class Solution {
public:
    int mySqrt(int long long x) {
        if(x==0||x==1) return x;
        int low=0,high=x,ans=0;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(mid*mid==x) return mid;
            if(mid*mid>x) high=mid-1;
            if(mid*mid< x ){
                low=mid+1;
                ans=mid;
            } 
        }
        return ans;  
    }
};