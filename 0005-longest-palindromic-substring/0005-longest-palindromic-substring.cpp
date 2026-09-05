class Solution {
public:

    string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            string odd = expandFromCenter(s, i, i);
            string even = expandFromCenter(s, i, i + 1);

            if (odd.size() > ans.size())
                ans = odd;

            if (even.size() > ans.size())
                ans = even;
        }

        return ans;
    }
};
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n=s.size();
//         string res={s[0]};
//         for(int k=0;k<n-1;k++){
//           int i=k-1,j=k+1;
//           string a={s[k]};
//           while( i>=0 &&j<n && s[i]==s[j]){
           
//              a=s[i]+a+s[i];
//              i--;
//              j++;
//           }
//           if(a.size()>res.size()){
//             res=a;
//           }
//            i=k,j=k+1;
//            a={};
//            while( i>=0 &&j<n && s[i]==s[j]){
           
//              a=s[i]+a+s[j];
//              i--;
//              j++;
//           }
//           if(a.size()>res.size()){
//             res=a;
//           }
//         }
//         //  for(int k=0;k<n-1;k++){
//         //   int i=k,j=k+1;
//         //   string a={};
         
//         // }
//          return res;
//     }
// };