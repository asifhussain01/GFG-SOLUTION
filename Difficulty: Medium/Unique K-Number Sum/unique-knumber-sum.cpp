class Solution {
  public:
    void solve(int start, int k, int n, vector<int>& path, vector<vector<int>>& ans) {
        // Base case: if we have picked k numbers
        if (path.size() == k) {
            if (n == 0) ans.push_back(path);
            return;
        }

        // Try all numbers from start to 9
        for (int i = start; i <= 9; i++) {
            if (i > n) break; // no need to continue if current number exceeds remaining sum
            
            path.push_back(i);          // choose
            solve(i + 1, k, n - i, path, ans); // explore next numbers
            path.pop_back();            // backtrack
        }
    }

    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(1, k, n, path, ans);
        return ans;
    }
};
