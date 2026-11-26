class Solution {
public:
    bool canAliceWin(int n) {
       if(n<10){
        return 0;
       } 
       bool p =true;
       for(int i=10;i>=0;i--){
        if(n==i){
            return p;
        }
        if(n>i){
            n-=i;
            p=!p;
        }else{
            return !p;
        }
       }
       return true;
    }
};