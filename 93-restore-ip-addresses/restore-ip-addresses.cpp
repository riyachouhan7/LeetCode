class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, 0, path, result);
        return result;
    }
    
    void backtrack(string& s, int idx, int dots, vector<string>& path, vector<string>& result) {
        if (dots == 4 && idx == s.size()) {
            // Form the IP from path
            result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }
        if (dots > 4) return; // invalid
        
        for (int len = 1; len <= 3; len++) {
            if (idx + len > s.size()) break;
            string segment = s.substr(idx, len);
            
            // Check validity
            if ((segment[0] == '0' && segment.length() > 1) || stoi(segment) > 255) {
                continue;
            }
            
            path.push_back(segment);
            backtrack(s, idx + len, dots + 1, path, result);
            path.pop_back();
        }
    }
};
