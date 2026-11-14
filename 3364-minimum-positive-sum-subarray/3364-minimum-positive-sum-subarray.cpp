class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res=INT_MAX;
        for(int i=l;i<=r;i++){
            int c=0;
            for(int j=0;j<nums.size();j++ ){
                if(j<i){
                    c+=nums[j];
                }else{
                    if(c>0){
                       res=min(res,c);
                    }
                   
                    c+=nums[j]-nums[j-i];
                }
            }
            if(c>0){
                res=min(res,c); 
            }
        }
        if(res!=INT_MAX){
            return res;
        }else{
            return -1;
        }
    }
};