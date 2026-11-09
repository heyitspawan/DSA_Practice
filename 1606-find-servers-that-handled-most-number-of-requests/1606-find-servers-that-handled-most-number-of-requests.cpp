
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        int n = arrival.size();

        vector<int> count(k, 0);

        // Available servers
        set<int> fserver;

        // {finish_time, server_index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > bserver;

        for (int i = 0; i < k; i++) {
            fserver.insert(i);
        }

        for (int i = 0; i < n; i++) {

            // Release completed servers
            while (!bserver.empty() &&
                   bserver.top().first <= arrival[i]) {

                auto [time, server] = bserver.top();
                bserver.pop();

                fserver.insert(server);
            }

            if (fserver.empty()) {
                continue;
            }

            // Circular server selection
            int target = i % k;

            auto it = fserver.lower_bound(target);

            if (it == fserver.end()) {
                it = fserver.begin();
            }

            int server = *it;

            fserver.erase(it);

            count[server]++;

            // Update server's finishing time
            bserver.push({
                arrival[i] + load[i],
                server
            });
        }

        // Find busiest servers
        int maxCount = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxCount) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
