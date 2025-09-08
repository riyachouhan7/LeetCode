class Solution {
public:
    bool iszero(int x)
    {
        while (x > 0) {
            if (x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++)
        {
            int b = n-i;
            if(iszero(i) && iszero(b))
            {
                return {i,b};
            }
        }
        return {};
    }
};