class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool des = false;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                for (int j = n - 1; j >= i; j--) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[j], nums[i - 1]);
                        reverse(nums.begin() + i, nums.end());
                        des = false;
                        break;
                    }
                }break;

            } else {
                des = true;
            }
        }
        if (des) {
            reverse(nums.begin(), nums.end());
        }
    }
};