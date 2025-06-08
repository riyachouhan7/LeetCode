class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buying = prices[0];
        int selling = 0;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)
        {
            selling = prices[i] - buying;
            maxProfit = max(maxProfit, selling);
            buying = min(buying, prices[i]);
        }
        return maxProfit;
    }
};