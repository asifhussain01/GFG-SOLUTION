#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Step 1: Topological sort (Kahn’s Algorithm)
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0) q.push(i);
        
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        // Step 2: Position of each node in topo order
        vector<int> pos(V);
        for (int i = 0; i < V; i++)
            pos[topo[i]] = i;

        // Step 3: Total possible forward edges in topo order
        int totalPossible = (V * (V - 1)) / 2;

        // Step 4: Count existing forward edges
        int existingForward = 0;
        for (auto &e : edges) {
            if (pos[e[0]] < pos[e[1]]) existingForward++;
        }

        // Step 5: Answer = total forward pairs - existing edges
        return totalPossible - existingForward;
    }
};

