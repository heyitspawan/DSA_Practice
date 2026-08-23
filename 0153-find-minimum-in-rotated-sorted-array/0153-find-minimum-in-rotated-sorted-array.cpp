class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int s = nums.size();
        int r = s - 1;
        int m;
        while (l <= r) {
            m = (l + r )/ 2;
            if (nums[l] > nums[r]) {
                if (nums[l] <= nums[m]) {
                    l = m + 1;
                } else {
                    if (nums[m] < nums[r]) {
                        r = m;
                    }
                }
            }
            if (nums[l] <= nums[r]) {
                return nums[l];
            }
        }
        return nums[m];
    }
};