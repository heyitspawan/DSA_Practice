class Solution {
public:
    int sol(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        int res = 0;
        int pick =0;
        int npick=0;
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        if (j==-1||nums[j] <nums[i]) {
            if (i + 1 < nums.size()) {
                pick = 1 + sol(i + 1, i, nums, dp);
                npick = sol(i + 1, j, nums, dp);
               
            }else{
                pick=1;
            }

        } else {
            if (i + 1 < nums.size()) {
                npick = sol(i + 1, j, nums, dp);
            }
        }
        res = max(pick, npick);
        return dp[i][j+1]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector< vector<int>> dp(n+1,vector<int>(n+1,-1));
        return sol(0,-1, nums, dp);
    }
};