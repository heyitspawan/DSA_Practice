class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        while(sum){
            for(int i=9;i>=0;i--){
                if(i<=sum){
                    res+=to_string(i);
                    sum-=i;
                    break;
                }
            }
        }
        int n=res.size();
        if(n<=num){
            int k=num-n;
            for(int i=0;i<k;i++){
                res+='0';
            }
        }else{
            return "";
        }
        return res;
        
    }
};