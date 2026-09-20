class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> a(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = image[i][j];
            }
        }
        queue<pair<int, int>> q;
        int ic = image[sr][sc];
        q.push({sr, sc});
        a[sr][sc] = color;
        vis[sr][sc]=1;
        while (!q.empty()) {
            int dr[] = {0, -1, 0, +1};
            int dc[] = {-1, 0, +1, 0};
            int row = q.front().first;
            int col = q.front().second;
                q.pop();
            for (int i = 0; i < 4; i++) {

                int nrow = row + dr[i];
                int ncol = col +dc[i];

                if (nrow>=0 && nrow<n &&ncol>=0 &&ncol<m && image[nrow][ncol] == ic&&vis[nrow][ncol]==-1) {
                    a[nrow][ncol] = color;
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
        return a;
    }
};