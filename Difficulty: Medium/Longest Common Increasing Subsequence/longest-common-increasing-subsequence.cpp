class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();

        // dp[j] = length of LCIS ending with b[j]
        vector<int> dp(m, 0);

        for (int i = 0; i < n; i++) {
            int currentMax = 0;

            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], currentMax + 1);
                }
                else if (a[i] > b[j]) {
                    currentMax = max(currentMax, dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
