class Solution {
public:
    int maxDepth(string s) {
       int c=0,a=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='(')  c++;
        if(s[i]==')')  
        {a=max(c,a);
          c--;}
       } 
        return a;
    }
   
};