// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         unordered_map<char,int> index;
//         int l=0,r=0;
//         for(int i=0;i<n;i++){
            
//             if (index.find(s[i]) != index.end() && index[s[i]] >= l) {
//                 l = index[s[i]] + 1;
//             }
//             index[s[i]] = i;
//             r=max(r,i-l+1);
//         }
//         return r;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int>hash(256,-1);
        int l=0,r=0,maxlen=0;
        int n=s.size();

        while(r<n){ 
            if(hash[s[r]]!=-1 && hash[s[r]]>=l) { 
                if(hash[s[r]>=l]) {  
                    l=hash[s[r]]+1;
                }
            }
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};