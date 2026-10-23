class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res=-1;
        vector<int>a=nums;
        sort(a.begin(),a.end());
        int f=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=a[i]&&f==0){
              res=nums[i];
              f=1;
            }
            else if(nums[i]!=a[i]){
                res&=nums[i];
            }else{
                continue;
            }
        }
        if(res==-1){
            return 0;
        }
        return res;
    }
};