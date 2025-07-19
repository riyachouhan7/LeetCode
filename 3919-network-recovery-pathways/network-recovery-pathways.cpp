class Solution {
public:
    bool isValid(long long minEdge, long long n, vector<vector<pair<long long, long long>>>& riya,
        vector<bool>& online, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, cost] : riya[u]) {
                if (cost < minEdge) continue;
                if (v != 0 && v != n - 1 && !online[v]) continue;
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] <= k;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        long long n = online.size();
        vector<vector<pair<long long, long long>>> riya(n);
        int maxCost = 0;
        for (auto &e : edges) {
            riya[e[0]].push_back({e[1], e[2]});
            maxCost = max(maxCost, e[2]);
        }
        
        long long low = 0, high = maxCost, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isValid(mid, n, riya, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};