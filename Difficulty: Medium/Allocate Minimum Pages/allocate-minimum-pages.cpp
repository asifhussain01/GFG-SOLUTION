class Solution {
  public:
    // Helper function: check if we can allocate with maxPages limit
    bool isPossible(vector<int>& arr, int k, int maxPages) {
        int students = 1;
        int pages = 0;

        for (int a : arr) {
            if (a > maxPages) return false; // one book itself exceeds limit
            if (pages + a > maxPages) {
                students++;
                pages = a;
                if (students > k) return false;
            } else {
                pages += a;
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // cannot allocate

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1; // try smaller maximum
            } else {
                low = mid + 1; // need larger maximum
            }
        }
        return ans;
    }
};
