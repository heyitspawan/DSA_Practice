class Solution {
public:
    bool checkDivisibility(int n) {
        int p=1,s=0;
        int o=n;
        while(n>0){
         int r=n%10;
         p*=r;
         s+=r;
         n/=10;
        }
        int sum=p+s;
        if(o%sum==0) return true;
        else return false;
    }
};