class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> a(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = grid[i][j];
                if (grid[i][j] == 1) {
                    f++;
                }
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        int t = 0;
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            t = max(t, time);
            q.pop();
            int dr[] = {0, -1, 0, +1};
            int dc[] = {-1, 0, +1, 0};
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == 1 &&
                    vis[ni][nj] != 1) {
                    f--;
                    vis[ni][nj] = 1;
                    a[ni][nj] = 2;

                    q.push({{ni, nj}, time + 1});
                }
            }
        }
        if (!f) {
            return t;
        } else
            return -1;
    }
};