class Solution {
public:

    int rec(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+rec(nums,i+2,dp);
        int notpick=rec(nums,i+1,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return rec(nums,0,dp);
    }
};