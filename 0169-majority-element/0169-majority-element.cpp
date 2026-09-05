class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int c = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == res) {
                c++;
            } else {
                if (c) {
                    c--;
                } else {
                    res = nums[i];
                    c = 1;
                }
            }
        }
        return res;
    }
};