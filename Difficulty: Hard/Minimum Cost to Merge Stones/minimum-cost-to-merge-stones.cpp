class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // Check if it's possible to end with 1 pile
        if ((n - 1) % (k - 1) != 0)
            return -1;

        // Prefix sum for fast range sum queries
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        // dp[i][j] = minimum cost to merge stones[i..j] into piles
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                // Try every partition in steps of k-1
                for (int m = i; m < j; m += (k - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }

                // After merging to k piles, we can merge them into 1 pile
                if ((len - 1) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};
