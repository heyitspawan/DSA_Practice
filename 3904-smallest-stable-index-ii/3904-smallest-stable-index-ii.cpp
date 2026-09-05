class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx = nums[0], mn = INT_MAX, flag = 0, n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefix[i] = mx;
        }
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            suffix[i] = mn;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (prefix[i] - suffix[i] <= k)
                return i;
        }
        // for(int i=0;i<nums.size();i++){
        //     if(!flag){
        //     vector<int>a(nums.begin()+i,nums.end());
        //     sort(a.begin(),a.end());

        //     mn=a[0];
        //     flag=1;
        //     }
        //     if(mn==nums[i]){
        //      flag=0;
        //     }
        //      mx=max(mx,nums[i]);
        //     if(mx-mn<=k) return i;

        // }
        return -1;
    }
};