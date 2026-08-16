class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cb= INT_MAX;
        int maxdiff = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            if (cb > prices[i]) {
                cb = prices[i];
                for (int j = i + 1; j < prices.size(); j++) {
                    if (prices[j] > prices[i]) {
                        maxdiff = max(maxdiff, (prices[j] - prices[i]));
                    }
                }
            }
        }
        return maxdiff;
    }
};