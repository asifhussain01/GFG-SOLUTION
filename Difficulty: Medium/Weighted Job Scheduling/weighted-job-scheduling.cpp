class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        
        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        vector<int> dp(n);
        dp[0] = jobs[0][2]; // profit of first job

        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];

            // Binary search to find last non-conflicting job
            int low = 0, high = i - 1, last = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    last = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (last != -1)
                includeProfit += dp[last];

            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }
};

