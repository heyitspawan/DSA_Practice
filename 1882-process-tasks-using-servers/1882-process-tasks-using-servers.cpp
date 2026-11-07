
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& task) {

        int n = task.size();
        vector<int> ans;

        // {available_time, weight, index}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq, pqs;

        for (int i = 0; i < servers.size(); i++) {
            pq.push({0, servers[i], i});
        }

        long long time = 0;
        int j = 0;

        while (j < n) {

            time = max(time, (long long)j);

            // Release all available servers
            while (!pqs.empty() && get<0>(pqs.top()) <= time) {

                auto [t, b, c] = pqs.top();
                pqs.pop();

                pq.push({0, b, c});
            }

            // If no server is available, jump forward
            if (pq.empty()) {
                time = get<0>(pqs.top());
                continue;
            }

            // Select the best server
            auto [a, b, c] = pq.top();
            pq.pop();

            ans.push_back(c);

            // Schedule the task
            pqs.push({
                time + task[j],
                b,
                c
            });

            j++;
        }

        return ans;
    }
};
