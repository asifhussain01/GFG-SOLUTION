class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        long long arrSum = 0, currVal = 0;

        // Calculate sum of all elements and initial i*arr[i]
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += (long long)i * arr[i];
        }

        long long maxVal = currVal;

        // Use the rotation formula
        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - (long long)n * arr[n - i];
            maxVal = max(maxVal, currVal);
        }

        return (int)maxVal;
    }
};
