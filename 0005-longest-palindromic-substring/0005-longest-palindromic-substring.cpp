class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res={s[0]};
        for(int k=0;k<n-1;k++){
          int i=k-1,j=k+1;
          string a={s[k]};
          while( i>=0 &&j<n && s[i]==s[j]){
           
             a=s[i]+a+s[i];
             i--;
             j++;
          }
          if(a.size()>res.size()){
            res=a;
          }
           i=k,j=k+1;
           a={};
           while( i>=0 &&j<n && s[i]==s[j]){
           
             a=s[i]+a+s[j];
             i--;
             j++;
          }
          if(a.size()>res.size()){
            res=a;
          }
        }
        //  for(int k=0;k<n-1;k++){
        //   int i=k,j=k+1;
        //   string a={};
         
        // }
         return res;
    }
};