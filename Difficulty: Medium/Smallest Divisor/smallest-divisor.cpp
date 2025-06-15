class Solution {
  public:
  int computeSum(const vector<int>& arr, int divisor) {
    int total = 0;
    for (int num : arr) {
        total += (num + divisor - 1) / divisor; // Efficient ceil
    }
    return total;
}
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
          int low = 1, high = *max_element(arr.begin(), arr.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int sum = computeSum(arr, mid);

        if (sum <= k) {
            ans = mid;
            high = mid - 1; // Try smaller divisor
        } else {
            low = mid + 1; // Need larger divisor
        }
    }
    return ans;
    }
};
