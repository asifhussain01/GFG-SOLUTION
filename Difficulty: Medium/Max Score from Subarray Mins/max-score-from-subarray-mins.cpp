class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
     int maxSum = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        int a = arr[i], b = arr[i + 1];
        maxSum = max(maxSum, a + b);
    }
    return maxSum;
    }
};