class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int s = nums.size();
        int r = s - 1;
        int m = nums[0];
        for (int i = 1; i < s; i++) {
            m = min(m, nums[i]);
        }
        return m;
    }
};