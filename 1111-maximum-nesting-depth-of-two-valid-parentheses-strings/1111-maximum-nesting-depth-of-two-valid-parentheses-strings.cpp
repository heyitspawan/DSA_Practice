class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int ma = 0, mb = 0, ca = 0, cb = 0;
        int n = seq.size();
        vector<int> res(seq.size(), -1);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                if (ca <= cb) {
                    res[i] = 0;
                    ca++;
                    ma = max(ma, ca);
                } else {
                    res[i] = 1;
                    cb++;
                    mb = max(mb, cb);
                }
            } else {
                if (ca >= cb) {
                    res[i] = 0;
                    ca--;
                } else {
                    res[i] = 1;
                    cb--;
                }
            }
        }
        return res;
    }
};