class Solution {
public:
    int dp[1001][2][1501];

    int solve(int i, int boughtFirst, vector<vector<int>>& items, vector<int>& freeCount, int bg) {
        int n = items.size();
        if (i >= n || bg <= 0) return 0;

        int& res = dp[i][boughtFirst][bg];
        if (res != -1) return res;

        int price = items[i][1];
        int pick = 0;

        if (bg >= price) {
            if (boughtFirst == 0) {
                pick = 1 + freeCount[i] + solve(i, 1, items, freeCount, bg - price);
            } else {
                pick = 1 + solve(i, 1, items, freeCount, bg - price);
            }
        }

        int npick = solve(i + 1, 0, items, freeCount, bg);
        return res = max(pick, npick);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;
        vector<int> freq(MAXF + 1, 0);
        for (auto& it : items) {
            freq[it[0]]++;
        }

        // multCount[d] = total items whose factor is divisible by d
        vector<int> multCount(MAXF + 1, 0);
        for (int d = 1; d <= MAXF; d++) {
            for (int m = d; m <= MAXF; m += d) {
                multCount[d] += freq[m];
            }
        }

        int n = items.size();
        vector<int> freeCount(n, 0);
        for (int i = 0; i < n; i++) {
            freeCount[i] = max(0, multCount[items[i][0]] - 1);
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, items, freeCount, budget);
    }
};