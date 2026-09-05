class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                mx=max(mx,c);
                c=0;
            }else{
               c++;
            }
           
        } 
        if(c!=0){
            mx=max(mx,c);
        }
        return mx;
    }
};