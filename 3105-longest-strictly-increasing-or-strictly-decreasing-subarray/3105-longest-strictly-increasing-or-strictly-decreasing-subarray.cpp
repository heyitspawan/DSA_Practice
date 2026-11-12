class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 0;
        int j = 0;
        int n=nums.size()-1;
        for (int i = 0; i < nums.size(); i++) {
            if (i+1<nums.size()&&nums[i] >= nums[i + 1]) {
                res = max(res, i - j + 1);
                j = i + 1;
            }else{
                res = max(res, i - j + 1);
            }
        }
        // res = max(res, n - j);
        j=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i-1>=0&&nums[i]>=nums[i-1]){
                res=max(res,j-i+1);
                j=i-1;
            }else{
               res=max(res,j-i+1);  
            }
        }
       // res=max(res,j+1);
        return res;
    }
};