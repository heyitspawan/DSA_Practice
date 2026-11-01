class Solution {
public:
   
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = 0;
        int j=nums[0];
         for (int i = 1; i < nums.size() ; i++) {
                c+=nums[i]-j;
         }
        return c;
    }
};