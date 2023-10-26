//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> ans;
        if(n == 1)
        {
            if(s == arr[0])
            {
                ans.push_back(1);
                return ans;
            }
            ans.push_back(-1);
            return ans;
        }
        if(s == 0)
        {
            ans.push_back(-1);
            return ans; 
        }
        int start = 0;
        int end = 0;
        int sum = 0;
        while(end < n)
        {
            sum += arr[end++];
            while(start < end && sum > s)
                sum -= arr[start++];
            if(sum == s)
            {
                ans.push_back(start + 1);
                ans.push_back(end);
                break;
            }
        }
        if(sum != s)
           ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends