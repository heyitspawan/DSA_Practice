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
        int n=nums.size();
        vector<bool>dp(nums.size(),false);
        if(n==1){
            return true;
        }
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            int j=1;
            while(j<=nums[i]&&i+j<n){
                if(dp[i+j]==true){
                    dp[i]=true;
                    break;
                }
                j++;
            }
        }
        return dp[0]; 
        
        }
};