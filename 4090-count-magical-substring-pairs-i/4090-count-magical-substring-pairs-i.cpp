class Solution {
public:
    int countMagicalPairs(string s) {
        int res = 0;
        for (int j = 0; j < s.size() - 1; j++) {
            unordered_set<char> st;
            int cnt[27] = {};
            int m1 = 0, m2 = 0;

            for (int i = j; i >= 0; i--) {
                m1 |= 1 << (s[i] - 'a');
                int dist1 = __builtin_popcount(m1);
                cnt[dist1]++;
            }
            for (int k = j + 1; k < s.size(); k++) {
                m2 |= 1 << (s[k] - 'a');
                int dist2 = __builtin_popcount(m2);
                res += cnt[dist2];
            }
        }

        return res;
    }
};