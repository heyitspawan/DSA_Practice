class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                set<int>s;
                for(int k=i;k<=j;k++){
                  s.insert(nums[k]);
                }
                int n=s.size();
                res+=n*n;
            }
        }
        return res;
    }
};