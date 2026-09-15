class Solution {
public:
    bool check(int i,int j, string s){
        if(j>=s.size()) return false;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int c=0;
        int i=0;
       while(i<s.size()){
            if(check(i,i+k-1,s)){
                c++;
                i=i+k;
            }
           else if(check(i,i+k,s)){
                c++;
                i=i+k+1;
            }
            else{
            i++;
            }
           
        }
        return c;
    }
};