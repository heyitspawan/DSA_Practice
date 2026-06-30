class Solution {
public:
    void f(int i, int j, vector<vector<char>>& grid,
           vector<vector<int>>& visited) {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < 4; k++) {
            int new_i = i + dir[k][0];
            int new_j = j + dir[k][1];
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 &&
                new_j < grid[0].size() && visited[new_i][new_j] != 1 &&
                grid[new_i][new_j] == '1') {
                visited[new_i][new_j] = 1;
                f(new_i, new_j, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j] == '1') {
                    visited[i][j] = 1;
                    res++;
                    f(i, j, grid, visited);
                }
            }
        }
        return res;
    }
};