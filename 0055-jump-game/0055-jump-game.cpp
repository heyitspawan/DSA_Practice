class Solution {
public:
    bool sol(vector<int>& nums, int i,vector<int>&dp) {
        if (i == nums.size() - 1) {
            return true;
        }
        if (i >= nums.size()) {
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for (int j = 1; j <= nums[i]; j++) {
            if (sol(nums, i + j,dp)==true) {
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) { 
        vector<int>dp(nums.size(),-1);
        return sol(nums, 0,dp); 
        
        }
};