class Solution {
  public:
    long long maxSubarraySum(vector<int> &arr) {
        long long currentSum = arr[0];
        long long maxSum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            // Either extend the current subarray or start new from arr[i]
            currentSum = max((long long)arr[i], currentSum + arr[i]);
            
            // Update maximum
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
