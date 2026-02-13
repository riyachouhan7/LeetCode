class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
            pq.push(stones[i]);
        while (pq.size() > 1)
        {
            int x1 = pq.top();
            pq.pop();
            int x2 = pq.top();
            pq.pop();
            if (x1 == x2)
                continue;
            else
            {
               
                int maxi = abs(x1-x2);
                pq.push(maxi);
            }
        }
        if (pq.size() == 0)
            return 0;
        else
            return pq.top();
    }
};