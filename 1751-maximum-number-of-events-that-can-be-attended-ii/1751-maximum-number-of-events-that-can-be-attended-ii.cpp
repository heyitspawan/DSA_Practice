class Solution {
public:

    int binarysearch(vector<vector<int>>& e, int i){
        int l = i + 1;
        int r = e.size() - 1;
        int res = -1;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(e[m][0] >e[i][1]){
                res = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return res;
    }

    int solve(vector<vector<int>>& e, int i, int k,
              vector<vector<int>>& dp){

        int n = e.size();

        if(i >= n || k == 0)
            return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        int ind = binarysearch(e, i);

        int pick = e[i][2];

        if(ind != -1)
            pick += solve(e, ind, k - 1, dp);

        int npick = solve(e, i + 1, k, dp);

        return dp[i][k] = max(pick, npick);
    }

    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end()); // sort by start time

        int n = events.size();

        vector<vector<int>> dp(
            n,
            vector<int>(k + 1, -1)
        );

        return solve(events, 0, k, dp);
    }
};