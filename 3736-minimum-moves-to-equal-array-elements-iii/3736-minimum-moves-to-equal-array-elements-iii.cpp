class Solution {
public:
    int minMoves(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int c=0;
        for(int i:nums){
            c+=abs(a-i);
        }
        return c;

        
    }
};