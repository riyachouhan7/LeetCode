class Solution {
public:
    bool canEat(vector<int>& piles, int h, int mid)
    {
        int hour = 0;
        for(auto it : piles)
        {
            hour += it/mid;
            if((it%mid) != 0)
            {
                hour++;
            }
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(canEat(piles, h, mid))
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        return l;
    }
};