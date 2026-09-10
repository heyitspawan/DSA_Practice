class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (l <=r) {
        //     if(l==r){
        //     if(nums[l]==target) return l;
        // }
            int m = (l + r) / 2;
            if (target == nums[m])
                return m;
            else if (target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};