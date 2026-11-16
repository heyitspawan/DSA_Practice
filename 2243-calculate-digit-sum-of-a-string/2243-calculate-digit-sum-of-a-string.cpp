class Solution {
public:
    string digitSum(string s, int k) {
        string b;
        int a = 0;
        if (s.size() > k) {
            a += s[0]-'0';
            for (int i = 1; i < s.size(); i++) {
                if (i % k == 0) {
                    b += to_string(a);
                    a = 0;
                }
                a += s[i]-'0';
            }
            b += to_string(a);
            return(digitSum(b,k));
        }else{
            return s;
        }
    }
};