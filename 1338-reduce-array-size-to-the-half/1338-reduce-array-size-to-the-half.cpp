class Solution {
public:

    int minSetSize(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        
        //int count;
        for(int i = 1; i < arr.size(); i++)
        {
            int count = 1;
            while(i < arr.size() && arr[i-1] == arr[i])
            {
                count++;
                i++;
            }
            pq.push(count);
        }
        int res = 0, sum = 0;
        
        while(sum < arr.size() / 2)
        {
            sum += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};