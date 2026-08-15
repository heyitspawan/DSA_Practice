class Solution {
public:
    // int f(int i,int j,int exor,vector<int>& nums, vector<vector<int>> & dp){
    //     if(j<=i) return 0;
    //     if(exor!=0) return j-i+1;
    //     if(dp[i][j]!=INT_MIN) return dp[i][j];
    //     int l= f(i,j-1,exor|nums[j], nums,dp);
    //    int r = f(i-1,j,exor|nums[i], nums,dp);
    //    return max(l,r);
    // }
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool non_zero=false;
        int exor =0;
       // vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        //dp[0][0]=nums[0];
        for(int i=0;i<nums.size();i++){
          exor^=nums[i];
          if(nums[i]!=0){
            non_zero= true ;
          }
        }
        if(exor!=0) 
        {
            return n;
        }else if(non_zero) return n-1;
        else 
        return 0;
    }
};