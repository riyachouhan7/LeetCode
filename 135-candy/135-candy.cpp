class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> LC(n,1), RC(n,1);
        
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                LC[i] = LC[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                RC[i] = RC[i+1]+1;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum  += max(LC[i], RC[i]);
        }
        return sum;
    }
};