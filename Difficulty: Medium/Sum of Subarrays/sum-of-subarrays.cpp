class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;

        for (int i = 0; i < n; ++i) {
            // Each element contributes to (i+1)*(n-i) subarrays
            long long contribution = (long long)(i + 1) * (n - i) * arr[i];
            totalSum += contribution;
        }

        return totalSum;
    }
};
