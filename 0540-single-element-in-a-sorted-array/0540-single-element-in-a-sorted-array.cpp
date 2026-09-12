
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 1)
            return nums[0];

        while (l <= r) {
            int m = l + (r - l) / 2;
            if(m==0 && nums[m] != nums[m +1]) return nums[m];
            if(m==nums.size() &&nums[m] != nums[m - 1]) return nums[m];
            if (nums[m] != nums[m - 1] && nums[m] != nums[m +1])
                return nums[m];
            else if (nums[m] == nums[m - 1]) {
                if ((m-1)%2==0) {
                    l=m+1;

                } else {
                    r = m -2;
                }
            } else {
                if (m % 2 == 0) {
                    l = m + 2;
                } else {
                    r= m -1;
                }
            }
        }
        return -1;
    }
};
