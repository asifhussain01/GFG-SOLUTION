class Solution {
  public:
    int backtrack(int left, int right, string& s, vector<vector<int>>& dp) {
        if (left >= right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        if (s[left] == s[right]) return dp[left][right] = backtrack(left + 1, right - 1, s, dp);
        else return dp[left][right] = 1 + min(backtrack(left + 1, right, s, dp),backtrack(left, right - 1, s, dp));
    }

    int minDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return backtrack(0, n-1, s, dp);
    }
};