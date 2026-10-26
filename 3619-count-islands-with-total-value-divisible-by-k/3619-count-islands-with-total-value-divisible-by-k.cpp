class Solution {
public:
    long long  sum=0;
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};
     bool bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        sum+=grid[i][j];
        queue<pair<int, int>> q;
       
        q.push({i, j});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
           
            for (int k = 0; k < 4; k++) {
                int ni = x + dr[k];
                int nj = y + dc[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    grid[ni][nj] != 0 && vis[ni][nj] == 0) {
                    vis[ni][nj] = 1;
                    sum+=grid[ni][nj];
                    q.push({ni, nj});
                }
            }
        }
        return true;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0 && vis[i][j] != 1 && bfs(i, j, grid, vis)) {
                    if(sum%k==0){
                        res++;
                    }
                    sum=0;
                }
            }
        }
        return res;
    }
};