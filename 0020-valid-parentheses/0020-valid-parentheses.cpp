class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                char c=s[i];
                char r=st.top();
                if(r=='(' && c==')') st.pop();
                else if(r=='{' && c=='}') st.pop();
                else if(r=='[' && c==']') st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};