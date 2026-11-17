class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                ans=max(ans,c);
                c=0;
            }
            else{
                c++;
            }
        
        }
         ans=max(ans,c);
         return ans;
    }
};