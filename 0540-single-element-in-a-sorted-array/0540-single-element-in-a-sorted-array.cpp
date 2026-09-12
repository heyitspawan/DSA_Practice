
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
    //     int l = 0, r = nums.size() - 1;
    //     if (nums.size() == 1)
    //         return nums[0];

    //     while (l <= r) {
    //         int m = l + (r - l) / 2;
    //         if (nums[m] != nums[m - 1] && nums[m] != nums[m +1])
    //             return nums[m];
    //         else if (nums[m] == nums[m - 1]) {
    //             if ((m - l + 1) % 2 != 0) {
    //                 r = m;

    //             } else {
    //                 l = m + 1;
    //             }
    //         } else {
    //             if ((r - m) % 2 == 0) {
    //                 r = m - 1;
    //             } else {
    //                 l = m + 1;
    //             }
    //         }
    //     }
    //     return -1;
    // }
};
