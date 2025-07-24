class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long current_time = 0;
        long long total_wait = 0;
        
        for (auto& customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            
            if (current_time < arrival) {
                current_time = arrival;
            }
            
            current_time += time;
            total_wait += (current_time - arrival);
        }
        
        return (double)total_wait / customers.size();
    }
};
