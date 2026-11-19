class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (binary_search(nums.begin(), nums.end(), target)) {
            auto [l, u] = equal_range(nums.begin(), nums.end(), target);
            int left_ind = l - nums.begin();
            int right_ind = u - nums.begin()-1;
            return {left_ind,right_ind};
        }else{
            return {-1,-1};
        }
    }
};