class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
    int n = mat.size();
    if (n == 0) return false;
    int m = mat[0].size();

    // Use a set to store pairs of columns that already have '1' in the same row
    unordered_set<int> pairs[201];  // maximum number of columns = 200

    for (int i = 0; i < n; ++i) {
        // For every row, check for column pairs having 1
        for (int c1 = 0; c1 < m; ++c1) {
            if (mat[i][c1] == 0) continue;
            for (int c2 = c1 + 1; c2 < m; ++c2) {
                if (mat[i][c2] == 1) {
                    // If we already saw this column pair in another row
                    int code = c1 * 200 + c2;
                    if (pairs[c1].count(c2)) return true;
                    pairs[c1].insert(c2);
                }
            }
        }
    }

    return false;
    }
};