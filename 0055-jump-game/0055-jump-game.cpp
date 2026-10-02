class Solution {
public:

    bool canJump(vector<int>& nums) { 
        int n=nums.size();
       // vector<bool>dp(nums.size(),false);
        if(n==1){
            return true;
        }
       int ind=n-1;
        //dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(ind-i<=nums[i]){
                ind=i;
            }
           
        }
        if(ind==0){
            return true;
        }
        return false; 
        
        }
};