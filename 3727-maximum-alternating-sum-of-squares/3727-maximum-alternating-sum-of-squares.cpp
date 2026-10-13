class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res=0;
        vector<int>a;
        for(int i:nums){
            a.push_back(abs(i));
        }
        sort(a.begin(),a.end());
        int n= nums.size();
        long long  ai=0;
        long long  bi=0;
        int c=0;
        for(int i:a){
            if(c<n/2){
                c++;
                ai+=i*i;
            }else{
                bi+=i*i;
            }
        }
        return bi-ai;
    }
};