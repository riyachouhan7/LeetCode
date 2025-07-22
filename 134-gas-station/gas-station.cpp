class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n) {
            int j = i;
            int curr = gas[i];
            while (curr >= cost[j]) {
                curr -= cost[j];
                curr += gas[(j + 1) % n];
                j = (j + 1) % n;
                if (j == i)
                    return i;
            }
            if(i == j) i++;
            else if(i < j) i = j;
            else break;
        }
        return -1;
    }
};