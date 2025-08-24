class Solution {
  public:
    // Helper function: check if we can make m bouquets by 'days'
    bool canMake(vector<int>& arr, int k, int m, int days) {
        int count = 0;     // consecutive bloomed flowers
        int bouquets = 0;  // total bouquets formed

        for (int bloomDay : arr) {
            if (bloomDay <= days) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0; // reset streak
            }
            if (bouquets >= m) return true; // already possible
        }
        return false;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long total = 1LL * k * m;
        if (total > arr.size()) return -1; // not enough flowers

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1; // try smaller days
            } else {
                low = mid + 1;  // need more days
            }
        }
        return ans;
    }
};
