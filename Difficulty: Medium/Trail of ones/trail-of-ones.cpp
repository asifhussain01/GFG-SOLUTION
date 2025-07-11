class Solution {
  public:
    int countConsec(int n) {
        // code here
        vector<int> dp(n + 1, 0);
    dp[0] = 1;  // empty string
    dp[1] = 2;  // "0", "1"

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int total = 1 << n;  // 2^n
    return total - dp[n];
    }
};