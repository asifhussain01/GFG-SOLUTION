class Solution {
  public:
    vector<int> parent, sz;
    vector<bool> active;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int longestSubarray(vector<int>& arr) {
        int n = arr.size();

        // store positions by value
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] <= n) pos[arr[i]].push_back(i);
        }

        parent.resize(n);
        sz.assign(n, 0);
        active.assign(n, false);
        iota(parent.begin(), parent.end(), 0);

        int ans = 0, maxComp = 0;

        for (int x = 1; x <= n; x++) {
            for (int idx : pos[x]) {
                active[idx] = true;
                sz[idx] = 1;
                parent[idx] = idx;

                if (idx > 0 && active[idx - 1]) unite(idx, idx - 1);
                if (idx + 1 < n && active[idx + 1]) unite(idx, idx + 1);

                maxComp = max(maxComp, sz[find(idx)]);
            }
            if (maxComp >= x) ans = x;
        }

        return ans;
    }
};
