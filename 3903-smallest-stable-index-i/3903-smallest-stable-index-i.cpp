class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx=nums[0] ,mn;
        for(int i=0;i<nums.size();i++){
            vector<int>a(nums.begin()+i,nums.end());
            sort(a.begin(),a.end());
            mx=max(mx,nums[i]);
            mn=a[0];
            if(mx-mn<=k) return i;

        }
        return -1;
    }
};