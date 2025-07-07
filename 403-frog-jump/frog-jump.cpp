class Solution {
public:
    bool rec(int from, int power, vector<int>& stones, vector<vector<int>>&dp){
        // if last index of the stone is reached, we got our solution
        if(from == stones.size()-1)    return true;

        if(dp[from][power] != -1)  //if previously visited, return its val
            return dp[from][power];

        //from our 'from' pointer with val = power-1 or power or power +1  (loop 1),   
        //we loop and check for any possible stones on which we can jump    (loop 2)
        for(int val = power-1;val<=power+1;val++){
            for(int to = from+1;to<stones.size();to++){

                // the difference stones[to] - stones[from] gives the calculated value
                // if the calculated values is more than the power permitted, there is no need
                // to check for further stones while holding the current power
                // increase power and check for other stones
                if(stones[to] - stones[from] > val)   
                    break;

                // if a suitable stone is found 
                if(stones[to]-stones[from] == val){
                    // uncomment the below comment to understand the jump flow fromt stone
                    // cout<<"from step "<<stones[ind]<<" jumped to  "<<stones[k]<<" with power "<<val<<endl;

                    // check for next stones, if answer found, return true
                    if(rec(to, val, stones, dp))   return dp[from][power] = true;

                    // uncomment the below comment to understand the jump flow fromt stone
                    // cout<<"going back to "<<stones[k]<<" cause ans not found\n";
                 
                }           
            }
        }
        return  dp[from][power] =  false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, 0, stones, dp);   //(from, initial power, stones, dp)
    }
};