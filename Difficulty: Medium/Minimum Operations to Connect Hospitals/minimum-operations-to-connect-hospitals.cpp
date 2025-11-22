class Solution {
  public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        
        // If not enough edges, cannot connect all hospitals
        if (E < V - 1) return -1;

        parent.resize(V);
        rankv.resize(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        for (auto &e : edges) {
            unite(e[0], e[1]);
        }

        int components = 0;
        for (int i = 0; i < V; i++) {
            if (find(i) == i) components++;
        }

        return components - 1;
    }
};

