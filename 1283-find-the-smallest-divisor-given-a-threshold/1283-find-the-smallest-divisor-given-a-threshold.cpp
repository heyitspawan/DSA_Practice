class Solution {
public:
    bool check(int m,vector<int>& nums, int threshold){
         int c=0;
    for(int i=0;i<nums.size();i++){
        double temp=(double)nums[i]/(double)m;
        if(temp>(int)temp){
            c+=(int)temp+1;
        }else{
            c+=(int)temp;
        }
    }
    if(c>threshold){
        return false;
    }else return true ;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int l=1,r = *max_element(nums.begin(), nums.end());
       if(threshold==nums.size()) return r;
        int ans=-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(check(m,nums,threshold)){
               ans=m;
               r=m;
            }else{
                l=m+1;
            }
        }
        return ans;
    } 
    
};