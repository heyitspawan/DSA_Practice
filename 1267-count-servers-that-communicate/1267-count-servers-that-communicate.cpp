class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // int dr[4]={0,-1,0,+1};
        // int dc[4]={-1,0,+1,0};
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int flag = 0;
                    for (int k = 0; k < n; k++) {
                        if (k != i && grid[k][j] == 1) {
                            c++;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        for (int k = 0; k < m; k++) {
                            if (k != j && grid[i][k] == 1) {
                                c++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};