class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       // int n=nums.size();
        vector<int>res(2*n);
       // int m=n/2;
       // int m=res.size()-1;
       int j=0;
        for(int i=0;i<n;i++){
            res[j]=nums[i];
            res[j+1]=nums[n+i];
            j+=2;
        }
        return res;  
    }
};