class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
        {
            return false;
        }
        int x = log2(n)/log2(3);
        if(pow(3,x) == n)
        {
            return true;
        }
        return false;
    }
};