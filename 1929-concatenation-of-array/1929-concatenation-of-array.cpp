class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(2*n,0);
        int m=res.size()-1;
        for(int i=0;i<n;i++){
            res[i]=nums[i];
            res[m-i]=nums[n-i-1];
        }
        return res;
    }
};