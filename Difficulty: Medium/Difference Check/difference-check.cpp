class Solution {
  public:
    // Helper to convert "HH:MM:SS" to total seconds
    int timeToSeconds(const string &time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr) {
        vector<int> seconds;
        
        // Convert each time to seconds
        for (const string &t : arr) {
            seconds.push_back(timeToSeconds(t));
        }

        // Sort the times
        sort(seconds.begin(), seconds.end());

        int minDiff = INT_MAX;
        int n = seconds.size();

        // Find minimum difference between consecutive times
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }

        // Handle circular difference (last to first across midnight)
        int fullDay = 24 * 3600; // 86400 seconds
        int circularDiff = fullDay - seconds[n - 1] + seconds[0];
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};
