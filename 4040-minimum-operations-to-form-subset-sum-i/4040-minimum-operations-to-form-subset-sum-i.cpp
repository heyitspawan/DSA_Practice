class Solution {
public:
    int sol(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
        if (i >= nums.size()) {
            if (sum == 0)
                return 0;
            else
                return INT_MAX;
        }
        if (sum == 0)
            return 0;
        if (sum < 0)
            return INT_MAX;

        if (dp[sum][i] != -1) {
            return dp[sum][i];
        }
        int pick = INT_MAX;
        int a = nums[i];
        int oper = 0;
        while (a <= sum) {
            int r1 = sol(nums, sum - a, i + 1, dp);
            if (r1 != INT_MAX) {
                pick = min(pick, oper + r1);
            }

            a = 2 * a;
            oper++;
        }
        oper = 0;
        int b = nums[i];
        while (b > 0) {
            int r2 = sol(nums, sum - b, i + 1, dp);
            if (r2 != INT_MAX) {
                pick = min(pick, oper + r2);
            }

            b = b / 2;
            oper++;
        }
        int npick = INT_MAX;

        npick = sol(nums, sum, i + 1, dp);

        return dp[sum][i] = min(pick, npick);
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        int flag = 0;
        vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
        int r4 = sol(nums, sum, 0, dp);
        if (r4 != INT_MAX) {
            return r4;
        }
        return -1;
    }
};