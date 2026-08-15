class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool non_zero = false;
        int exor = 0;

        for (int i = 0; i < nums.size(); i++) {
            exor ^= nums[i];
            if (nums[i] != 0) {
                non_zero = true;
            }
        }
        if (exor != 0) {
            return n;
        } else if (non_zero)
            return n - 1;
        else {
            return 0;
        }
    }
};