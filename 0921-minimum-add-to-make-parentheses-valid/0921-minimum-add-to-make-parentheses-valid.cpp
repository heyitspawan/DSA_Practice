class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0;
        
        int c=0;
        for(char i:s){
            if(i=='('){
                c++;
            }else if(i==')'&&c==0){
                res++;
            }else{
                c--;
            }
        }
        return res+c;;
    }
};