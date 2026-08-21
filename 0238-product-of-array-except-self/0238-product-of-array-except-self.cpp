class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        int pre=nums[0];
        int post=nums[n-1];
      for(int i=1;i<n;i++){
        res[i]=pre;
        pre*=nums[i];
    }
     for(int i=n-2;i>=0;i--){
        res[i]*=post;
        post*=nums[i];
    }
    return res;
    }
};