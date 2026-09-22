class Solution {

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int res = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    c++;
                }
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                    grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {

            int oi = q.front().first;
            int oj = q.front().second;
            vis[oi][oj] = 1;
            res++;
            q.pop();
            int dr[] = {0, -1, 0, +1};
            int dc[] = {-1, 0, +1, 0};
            for (int k = 0; k < 4; k++) {
                int ni = oi + dr[k];
                int nj = oj + dc[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    grid[ni][nj] == 1 && vis[ni][nj] == 0) {
                    vis[ni][nj] = 1;

                    q.push({ni, nj});
                }
            }
        }

        return c - res;
    }
};