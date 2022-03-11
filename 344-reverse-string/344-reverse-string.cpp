class Solution {
public:
    void reverseString(vector<char>& s) {
  int i=0,n=s.size(),j=n-1;
        while(i<j){
            swap(s[i],s[j]);i++;j--;
        }
        return;
    }
};