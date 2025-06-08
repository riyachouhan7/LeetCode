class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buying = prices[0];
        int selling = 0;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)
        {
            buying = min(buying, prices[i]);
            selling = prices[i] - buying;
            //maxProfit = max(maxProfit, sellingCost);
            // buying = min(buying, prices[i]);
            maxProfit = max(maxProfit, selling);
        }
        return maxProfit;
    }
};