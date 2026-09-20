class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
          int ind1=i+1;;
          int ind2=26-s[i]+'a';
          res+=ind1*ind2;
        }
        return res;
    }
};