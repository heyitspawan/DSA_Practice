class Solution {
public:
    int bestClosingTime(string customers) {
       int cn=0;
       for(int i=0;i<customers.size();i++){
       if(customers[i]=='N'){
            cn++;
        }
       } 
       int x=customers.size();
       int ans=cn;
       int p=cn;
       for(int i=x-1;i>=0;i--){
        if(customers[i]=='Y'){
            p++;
        }else{
            p--;
        }
        if(p<=ans){
            x=i;
            ans=p;
        }
       }
       return x;
    }
};