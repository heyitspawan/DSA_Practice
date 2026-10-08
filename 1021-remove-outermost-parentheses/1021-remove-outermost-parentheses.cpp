class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                if (st.size() == 1) {
                    int j = st.top();
                    res += s.substr(j+1, i-j-1);
                    st.pop();
                } else {
                    st.pop();
                }
            }
        }
        return res;
    }
};