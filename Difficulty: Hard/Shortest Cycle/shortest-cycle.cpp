#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = INT_MAX;

        // Step 2: Try BFS from every vertex
        for (int start = 0; start < V; start++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } 
                    // If visited and not parent => cycle found
                    else if (parent[u] != v) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

