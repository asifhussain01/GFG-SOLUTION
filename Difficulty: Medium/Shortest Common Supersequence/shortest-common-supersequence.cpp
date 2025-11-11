class Solution {
  public:
    // Function to find the length of the shortest common supersequence
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        // Step 1: Compute LCS length using DP
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int lcs = dp[n][m];
        
        // Step 2: SCS length = total length - overlapping (LCS)
        return n + m - lcs;
    }
};
