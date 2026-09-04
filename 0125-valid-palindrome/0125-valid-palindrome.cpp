class Solution {
public:
    bool isPalindrome(string s) {
      int n=s.size();
      int i=0,j=n-1;
      while(i<=j){
        if(isspace(s[i])||ispunct(s[i])){
            i++;
        }else if(isspace(s[j])||ispunct(s[j])){
            j--;
        }else{
            if(tolower(s[i])!=tolower(s[j])) return false;
            else{
                i++;
                j--;
            }
        }
      } return true ; 
    }
};