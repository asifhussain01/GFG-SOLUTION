class Solution {
  public:
    int n, m;
    int dp[101][101][101]; // dp[i][j][sum] → number of paths from (i, j) with current sum
    
    int solve(vector<vector<int>>& mat, int i, int j, int k) {
        // Base case: if out of bounds
        if (i >= n || j >= m) return 0;
        
        // If last cell reached
        if (i == n - 1 && j == m - 1) {
            return (k == mat[i][j]) ? 1 : 0;
        }

        // If already computed
        if (dp[i][j][k] != -1) return dp[i][j][k];
        
        // Reduce k by the coins at current cell
        int remaining = k - mat[i][j];
        if (remaining < 0) return dp[i][j][k] = 0;

        // Move right or down
        int right = solve(mat, i, j + 1, remaining);
        int down  = solve(mat, i + 1, j, remaining);
        
        return dp[i][j][k] = right + down;
    }
    
    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(mat, 0, 0, k);
    }
};
