class Solution {
public:
bool check(int m,vector<int>& piles, int h){
    int c=0;
    for(int i=0;i<piles.size();i++){
        double temp=(double)piles[i]/(double)m;
        if(temp>(int)temp){
            c+=(int)temp+1;
        }else{
            c+=(int)temp;
        }
    }
    if(c>h){
        return false;
    }else return true ;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9+5;
        int ans;
        while(l<r){
            int m=l+(r-l)/2;
            if(check(m,piles,h)){
               ans=m;
               r=m;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};