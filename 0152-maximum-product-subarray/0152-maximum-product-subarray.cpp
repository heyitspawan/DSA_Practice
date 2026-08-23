class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int s = nums.size();

        int cs = 1, sum1 = nums[0];
        for (int i = 0; i < nums.size(); i++) {

            cs = cs * nums[i];
            sum1 = max(cs, sum1);
            if (cs == 0)
                cs = 1;
        }
        cs = 1;
        for (int i = s - 1; i >= 0; i--) {

            cs = cs * nums[i];
            sum1 = max(cs, sum1);
            if (cs == 0)
                cs = 1;
        }
        return sum1;
    }
};