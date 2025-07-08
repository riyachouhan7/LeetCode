class Solution {
public:
    double possible(vector<int>& dist, int midSpeed)
    {
        double time = 0.0;
        int n = dist.size();
        for(int i=0;i<n-1;i++)
        {
            double t = (double)dist[i]/ (double)midSpeed;
            time += ceil(t);
        }
        time += (double)dist[n-1]/ (double)midSpeed;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        int minSpeed = -1;
        while(l<=r)
        {
            int midSpeed = l + (r-l)/2;
            if(possible(dist, midSpeed) <= hour)
            {
                minSpeed = midSpeed;
                r = midSpeed - 1;
            }
            else
            {
                l = midSpeed + 1;
            }
        }
        return minSpeed;
    }
};