class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && k > 0) {
                k--;
                 res=max(res,i-j+1);
                continue;
            }
            if(nums[i]==1){
                 res=max(res,i-j+1);
                continue;
            }
            if(nums[i] == 0 && k == 0){
                res=max(res,i-j);
                while(j<nums.size())
                {
                    if(nums[j]==0){
                        k++;
                        j++;
                        break;
                        
                    }else{
                        j++;
                    }
                }
            }
            k--;
        }
        return res;
    }
};