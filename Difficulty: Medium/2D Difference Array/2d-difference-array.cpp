class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Step 1: Create a diff matrix of size (n+2) x (m+2)
        vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));
        
        // Step 2: Apply all operations on the diff matrix
        for (auto& op : opr) {
            int v = op[0];
            int r1 = op[1];
            int c1 = op[2];
            int r2 = op[3];
            int c2 = op[4];
            
            diff[r1][c1] += v;
            diff[r1][c2 + 1] -= v;
            diff[r2 + 1][c1] -= v;
            diff[r2 + 1][c2 + 1] += v;
        }
        
        // Step 3: Prefix sum row-wise
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        // Step 4: Prefix sum column-wise
        for (int j = 0; j < m + 1; ++j) {
            for (int i = 1; i < n + 1; ++i) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // Step 5: Apply diff to the original matrix
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = mat[i][j] + diff[i][j];
            }
        }

        return result;
    }
};
