class Solution {
public:
      int rec(vector<int>& nums,int i,int n,vector<int>&dp){
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+rec(nums,i+2,n,dp);
        int notpick=rec(nums,i+1,n,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
         vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(rec(nums,0,n-2,dp1),rec(nums,1,n-1,dp2));
    }
};