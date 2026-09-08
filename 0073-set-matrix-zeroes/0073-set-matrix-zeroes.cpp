class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> a(n, -1);
        vector<int> b(m, -1);
        // vector<vector<int>> v(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    a[i] = 0;
                    b[j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (a[i] == 0 || b[j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};