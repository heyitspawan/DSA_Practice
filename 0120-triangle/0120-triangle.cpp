class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int res = t[0][0];
        int n = t.size();
        int m = t[n - 1].size();
        vector<long long> a(m, -1);
        for (int i = 0; i < m; i++) {
            a[i] = t[n - 1][i];
        }
        for (int i = n-2; i >=0; i--) {
            for (int j = 0; j<=i; j++) {
                a[j] = t[i][j] + min(a[j],a[j+1]);
            }
        }
 return a[0];
      
    }
};