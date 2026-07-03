#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> max_depth(n + 1, -1);
        int total_groups = 0;

        for (int i = 1; i <= n; ++i) {
            if (max_depth[i] != -1) continue;

            // Find all nodes in the current component
            vector<int> component;
            queue<int> q;
            q.push(i);
            max_depth[i] = 0; // Mark as visited
            component.push_back(i);

            int head = 0;
            while(head < component.size()){
                int u = component[head++];
                for(int v : adj[u]){
                    if(max_depth[v] == -1){
                        max_depth[v] = 0;
                        component.push_back(v);
                        q.push(v);
                    }
                }
            }

            // Try BFS from each node in the component to find max depth
            int component_max = 0;
            for (int start_node : component) {
                int depth = bfs(start_node, adj, n);
                if (depth == -1) return -1;
                component_max = max(component_max, depth);
            }
            total_groups += component_max;
        }

        return total_groups;
    }

private:
    int bfs(int start_node, const vector<vector<int>>& adj, int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        dist[start_node] = 1;
        q.push(start_node);
        
        int max_d = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            max_d = max(max_d, dist[u]);
            
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if (abs(dist[v] - dist[u]) != 1) {
                    return -1; // Not bipartite
                }
            }
        }
        return max_d;
    }
};