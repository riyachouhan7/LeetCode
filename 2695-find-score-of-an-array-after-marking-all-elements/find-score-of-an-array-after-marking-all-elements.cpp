class Solution {
public:
    #define P pair<int,int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i], i});
        }

        long long score = 0;
        while(!pq.empty())
        {
            P temp = pq.top();
            int element = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            if(!visited[ind])
            {
                visited[ind] = true;
                score += element;

                if(ind-1 >= 0 && !visited[ind-1])
                {
                    visited[ind-1] = true;
                }
                if(ind+1 < n && !visited[ind+1])
                {
                    visited[ind+1] = true;
                }
            } 
        }
        return score;
    }
};