class Solution {
  public:
    int kadane(vector<int> &arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < m; left++) {
            vector<int> temp(n, 0);

            for (int right = left; right < m; right++) {
                for (int row = 0; row < n; row++) {
                    temp[row] += mat[row][right];
                }

                int currMax = kadane(temp);
                maxSum = max(maxSum, currMax);
            }
        }

        return maxSum;
    }
};
