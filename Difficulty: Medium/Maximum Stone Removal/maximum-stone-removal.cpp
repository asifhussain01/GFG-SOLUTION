class Solution {
public:
    vector<int> parent, rankv;

    int findp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findp(parent[x]);
    }

    void unionp(int a, int b) {
        a = findp(a);
        b = findp(b);
        if (a == b) return;

        if (rankv[a] < rankv[b]) parent[a] = b;
        else if (rankv[b] < rankv[a]) parent[b] = a;
        else {
            parent[b] = a;
            rankv[a]++;
        }
    }

    int maxRemove(vector<vector<int>>& stones) {
        int maxCoord = 10005; // max row/col offset
        parent.resize(20010);
        rankv.resize(20010, 0);

        for (int i = 0; i < 20010; i++) parent[i] = i;

        unordered_set<int> used; // track used DSU nodes

        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + 10001; // shift column index

            unionp(row, col);
            used.insert(row);
            used.insert(col);
        }

        int components = 0;
        for (int node : used) {
            if (findp(node) == node) components++;
        }

        return stones.size() - components;
    }
};
