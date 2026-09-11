class Solution {
public:
    bool bs(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return true;
            else {
                if(nums[l]==nums[m]&&nums[m]==nums[r]){
             l++;
             r--;
                }
                else if (nums[l] <=nums[m]) {
                    if (target >= nums[l] && target < nums[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    if (target >nums[m] && target <= nums[r]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }return false;
    }
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        return bs(l, r, nums, target);
    }
};