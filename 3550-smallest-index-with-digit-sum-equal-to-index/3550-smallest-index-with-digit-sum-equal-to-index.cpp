class Solution {
public:
bool check(int i,int j){
    int sum=0;
    while(j>0){
        sum+=j%10;
        j=j/10;
    }
    if(i==sum) return true;
    else return false;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(check(i,nums[i])){
                return i;
            }
        }
        return -1;
    }
};