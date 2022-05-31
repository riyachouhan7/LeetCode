class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        if(n%2 == 0)
            return myPow(x*x, n/2);
        else
            return myPow(x, n/abs(n)) * myPow(x*x, n/2);
    }
};