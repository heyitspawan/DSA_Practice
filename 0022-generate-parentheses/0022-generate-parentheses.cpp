class Solution {
public:
    void sol(string s, vector<string>& res, int i, int j) {
        if (i == 0 && j == 0) {
            res.push_back(s);
            return;
        }
        if (i < 0 || j < 0) {
            return;
        }
        if (!s.size()) {
            sol(s + '(', res, i - 1, j);
        } else {
            int n = s.size();
            if (s[n - 1] == '(') {
                if (i > 0) {
                    sol(s + '(', res, i - 1, j);
                }
                if (j > i) {
                    sol(s + ')', res, i, j - 1);
                }

            } else {
                if (i > 0) {
                    sol(s + '(', res, i - 1, j);
                }
                if (j > i) {
                    sol(s + ')', res, i, j - 1);
                }
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        sol("", res, n, n);
        return res;
    }
};