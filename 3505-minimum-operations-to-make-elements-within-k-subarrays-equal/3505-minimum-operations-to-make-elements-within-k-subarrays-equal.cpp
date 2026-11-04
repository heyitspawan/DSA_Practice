
class Solution {
public:

    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void rebalance() {
        while (low.size() > high.size() + 1) {
            int val = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < high.size()) {
            int val = *high.begin();
            high.erase(high.begin());
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    void add(int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }

        rebalance();
    }

    void remove(int val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }

        rebalance();
    }

    long long getCost() {
        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        // Calculate cost of every window
        vector<long long> op;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        for (int i = 0; i + x <= n; i++) {

            op.push_back(getCost());

            if (i + x < n) {
                remove(nums[i]);
                add(nums[i + x]);
            }
        }

        int m = op.size();

        const long long INF = LLONG_MAX / 4;

        // Bottom-up DP
        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(m + x + 1, INF)
        );

        // Base case: selecting zero windows costs zero
        for (int i = 0; i <= m + x; i++) {
            dp[0][i] = 0;
        }

        for (int cnt = 1; cnt <= k; cnt++) {

            for (int i = m - 1; i >= 0; i--) {

                // Not selecting current window
                long long notPick = dp[cnt][i + 1];

                // Selecting current window
                long long pick = op[i] + dp[cnt - 1][i + x];

                dp[cnt][i] = min(pick, notPick);
            }
        }

        return dp[k][0];
    }
};
