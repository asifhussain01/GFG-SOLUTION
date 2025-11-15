class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        // Add 0 and n to the list of cuts
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        
        // dp[i][j] = minimum cost to cut between cuts[i] and cuts[j]
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // length = interval size
        for (int len = 2; len < m; len++) {
            for (int i = 0; i < m - len; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(
                        dp[i][j],
                        cuts[j] - cuts[i] + dp[i][k] + dp[k][j]
                    );
                }
            }
        }
        
        return dp[0][m - 1];
    }
};
