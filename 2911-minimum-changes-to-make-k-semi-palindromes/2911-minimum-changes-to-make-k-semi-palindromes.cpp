class Solution {
public:
    vector<vector<long long>> v;
    vector<long long> factor(long long n) {
        vector<long long> ans;
        for (long long i = 1; i < n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    long long check(string p) {
        long long c = 0;
        long long i = 0;
        long long j = p.size() - 1;
        while (i <= j) {
            if (p[i] != p[j]) {
                c++;
            }
            i++;
            j--;
        }
        return c;
    }
    long long costcalculate(string& s, long long i, long long j) {
        long long len = j - i + 1;
        vector<long long> div = factor(len);

        long long cost = LLONG_MAX;

        for (long long k = 0; k < div.size(); k++) {
            long long d = div[k];
            long long sum = 0;

            for (long long p = 0; p < d; p++) {
                string a;

                for (long long q = i + p; q <= j; q += d) {
                    a += s[q];
                }

                sum += check(a);
            }

            cost = min(cost, sum);
        }

        return cost;
    }
    long long solve(string& s, long long i, long long k,
                    vector<vector<long long>>& dp) {
        long long n = s.size();
        if (k == 0) {
            if (i == s.size()) {
                return 0;
            } else {
                return LLONG_MAX;
            }
        }
        if (i + 2 * k > n) {
            return LLONG_MAX;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        long long cost = LLONG_MAX;
        for (long long j = i + 1; j < s.size(); j++) {
            long long rc = solve(s, j + 1, k - 1, dp);
            if (rc != LLONG_MAX) {
                long long costpartition = costcalculate(s, i, j);
                cost = min(cost, costpartition + rc);
            }
        }
        return dp[i][k] = cost;
    }
    int minimumChanges(string s, int k) {
        long long n = s.size();
        v.resize(n, vector<long long>(n, 0));
        for (long long i = 0; i < n; i++) {
            for (long long j = i + 1; j < n; j++) {
                v[i][j] = check(s.substr(i, j - i + 1));
            }
        }
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1));
        return (int)solve(s, 0, k, dp);
    }
};