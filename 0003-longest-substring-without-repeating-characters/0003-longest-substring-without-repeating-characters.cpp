class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int i = 0, mx = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            while (seen.count(s[j])) {
                seen.erase(s[i]);
                i++;
            }
            seen.insert(s[j]);
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};