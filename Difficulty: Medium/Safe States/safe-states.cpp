#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Step 1: Build reverse graph
        vector<vector<int>> rev(V);
        vector<int> indegree(V, 0);
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            rev[v].push_back(u);
            indegree[u]++;
        }
        
        // Step 2: Kahn's algorithm (Topological Sort)
        queue<int> q;
        vector<int> safe;
        
        // Terminal nodes (in reversed graph, indegree == 0)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (int nei : rev[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        
        // Step 3: Sort safe nodes for ascending order
        sort(safe.begin(), safe.end());
        return safe;
    }
};
