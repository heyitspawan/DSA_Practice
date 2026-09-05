class Solution {
public:
 int expandFromCenter(string s, int left, int right) {
    int count=0;
    //int j=right;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
    // if(i==j){
    //     return i-left+1;
    // }else{
    //     return (right - left - 1)/2;
    // }
    return count ;
       
    }
    int countSubstrings(string s) {
        int ans=0;
        for (int i = 0; i < s.size(); i++) {

            int odd = expandFromCenter(s, i, i);
            int even = expandFromCenter(s, i, i + 1);

            ans+=odd+even;
        }

        return ans;
    }
};
