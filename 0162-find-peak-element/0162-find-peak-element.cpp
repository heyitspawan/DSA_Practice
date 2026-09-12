class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int l = 0, n = nums.size() - 1, r = nums.size() - 1, m = -1;

        while (l < r) {
            m = l + (r - l) / 2;

            if (nums[m] < nums[m + 1]) {
                // Moving upward, so a peak exists on the right
                l = m + 1;
            } 
            else {
                // Moving downward, so a peak exists at m or on the left
                r = m;
            }
        }

        return l;
    }
};