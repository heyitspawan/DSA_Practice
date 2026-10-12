class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>c(32,0);
        long long res=0;
        for(int i=0;i<nums.size();i++){
             for(int b=0;b<32;b++){
                if(nums[i]&(1<<b)){
                    c[b]++;
                }
             }
        }
        while(k--){
            long long  p=0;
           for(int b=0;b<32;b++){
            if(c[b]>0){
                p=p|(1<<b);
                c[b]--;
            }
           }
           res=(res+(long long)(p*p)%(long long)(1e9+7))%(long long)(1e9+7);
        }
        
        return (int)res;
    }
};