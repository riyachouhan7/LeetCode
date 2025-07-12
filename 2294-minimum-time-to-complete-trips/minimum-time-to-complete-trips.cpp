class Solution {
public:
    bool solve(vector<int>& time, int totalTrips, long long n){
        long long sum = 0;
        for(auto i : time) {
            sum += n / i;
            if(sum >= totalTrips) return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = 1e14;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(solve(time, totalTrips, mid))
            {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return l;
    }
};