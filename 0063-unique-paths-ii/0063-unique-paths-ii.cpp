class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        if (o[n - 1][m - 1] == 1)
            return 0;
        // if(n==1||m==1) return 1;
        vector<vector<long long >> dp(n, vector<long long >(m, -1));
        bool flag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (o[i][m - 1] == 1 || flag) {
                dp[i][m - 1] = 0;
                flag = true;
            } else {
                dp[i][m - 1] = 1;
            }
        }

        flag = false;
        for (int i = m - 1; i >= 0; i--) {
            if (o[n - 1][i] == 1 || flag) {
                dp[n - 1][i] = 0;
                flag = true;
            } else {
                dp[n - 1][i] = 1;
            }
        }
        for (int i = n - 2; i > -1; i--) {
            for (int j = m - 2; j > -1; j--) {
                if (o[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};