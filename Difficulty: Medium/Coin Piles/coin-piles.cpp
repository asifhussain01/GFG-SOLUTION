class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int remLeft = prefix[i];
            int upper = upperBound(arr, arr[i] + k);
            int remRight = prefix[n] - prefix[upper] - (n - upper) * (arr[i] + k);
            ans = min(ans, remLeft + remRight);
        }

        return ans;
    }

private:
    int upperBound(vector<int>& arr, int v) {
        int lo = 0, hi = arr.size() - 1, ans = arr.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] <= v) {
                lo = mid + 1;
            } else {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};