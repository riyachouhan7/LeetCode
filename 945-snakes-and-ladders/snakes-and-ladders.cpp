class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flat(n * n + 1, -1); // 1-indexed

        // Flatten the board
        int idx = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    flat[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flat[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int> q;
        vector<bool> visited(n * n + 1, false);

        q.push(1);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front(); q.pop();
                if (curr == n * n) return moves;

                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > n * n) continue;

                    if (flat[next] != -1) {
                        next = flat[next];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }

        return -1; // Not possible
    }
};
