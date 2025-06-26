class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Add all rotten oranges to queue and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;  // No fresh orange

        int time = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
