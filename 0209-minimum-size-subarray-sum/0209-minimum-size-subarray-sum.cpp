class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 1e9;
        int left = 0;
        int csum = 0;
        for (int right = 0; right < nums.size(); right++) {
            csum += nums[right];
            while (csum >= target) {
                res = min(res, right - left + 1);
                csum -= nums[left];
                left += 1;
            }
        }

        if (res == 1e9)
            return 0 ;   
        else
            return res;
    }
};