class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
        {
            return false;
        }
        int x = log2(n)/log2(4);
        if(pow(4,x) == n)
        {
            return true;
        }
        return false;
    }
};