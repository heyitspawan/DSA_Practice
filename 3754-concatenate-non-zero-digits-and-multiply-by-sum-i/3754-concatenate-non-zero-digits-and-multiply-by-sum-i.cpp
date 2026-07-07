class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long  res=0;
        int i=1;
        //int vector<int> res;
        while(n>0){
            long long  a=n%10;
            if(a!=0){
                sum+=a;
               res+=(long long )a*i;
               i*=10;
               //res.push_front(a);
            }
             n/=10;
        
        }
        return res*sum;
    }
};