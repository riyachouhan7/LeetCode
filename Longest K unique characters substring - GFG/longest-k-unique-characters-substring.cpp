//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    
       int i = 0 , j = 0 , n = s.size();;
       unordered_map<char , int> mp;
       int maxLen = -1;
       
    
       while(j < n){
       
         mp[s[j]]++;
         
         if(mp.size() > k){
             
             while(mp.size() > k){
                 mp[s[i]]--;
                 
                 if(mp[s[i]] == 0)
                 mp.erase(s[i]);
                 i++;
             }
         }
         
         if(mp.size() == k)
         maxLen = max(maxLen , j-i+1);
         
         j++;
      }
      
      return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends