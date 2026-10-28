class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string co) {
        int n = edges.size();

        vector<int> out(n + 1, 0);
        vector<int> in(n + 1, 0);

        for (auto x : edges) {
            int u = x[0];
            int v = x[1];

            if (co[u] == co[v])
                return -1;

            if (co[u] == 'R') {
                if (co[v] == 'W') {
                    in[u]++;
                    out[v]++;
                }

                if (co[v] == 'B') {
                    in[v]++;
                    out[u]++;
                }
            }

            if (co[u] == 'B') {
                if (co[v] == 'R') {
                    in[u]++;
                    out[v]++;
                }

                if (co[v] == 'W') {
                    in[v]++;
                    out[u]++;
                }
            }

            if (co[u] == 'W') {
                if (co[v] == 'B') {
                    in[u]++;
                    out[v]++;
                }

                if (co[v] == 'R') {
                    in[v]++;
                    out[u]++;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            if (in[i] > 1)
                return -1;

            if (out[i] > 2)
                return -1;
        }

        for (int i = 0; i <= n; i++) {
            if (in[i] == 0)
                return i;
        }

        return -1;
    }
};