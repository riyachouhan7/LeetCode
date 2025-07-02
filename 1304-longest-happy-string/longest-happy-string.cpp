class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string s = "";

        while(!pq.empty()) {
            auto [currCount, currChar] = pq.top();
            pq.pop();

            int len = s.size();
            if(len >= 2 && s[len - 1] == currChar && s[len - 2] == currChar) {
                if(pq.empty()) break; // no other char available

                auto [nextCount, nextChar] = pq.top();
                pq.pop();

                s.push_back(nextChar);
                nextCount--;
                if(nextCount > 0) pq.push({nextCount, nextChar});
                pq.push({currCount, currChar}); // push back current
            }
            else {
                s.push_back(currChar);
                currCount--;
                if(currCount > 0) pq.push({currCount, currChar});
            }
        }

        return s;
    }
};
