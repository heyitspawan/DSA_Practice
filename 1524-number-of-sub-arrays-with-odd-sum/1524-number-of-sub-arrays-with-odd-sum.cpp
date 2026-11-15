class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int res = 0;
        int evencount=1;
        int oddcount=0;
        int prefix=0;
        for (int i = 0; i < arr.size(); i++) {
           prefix+=arr[i];
           if(prefix%2==0){
            res=(res+oddcount)%(int)(1e9+7);
            evencount++;
            prefix=0;

           }else{
             res=(res+evencount)%(int)(1e9+7);
             oddcount++;
             prefix=1;
           }
        }
        return res;
    }
};