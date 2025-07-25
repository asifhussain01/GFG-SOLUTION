class Solution {
  public:
  
    int kadaneMaxSum(vector<int>& arr) {
        int maxEndingHere = arr[0], maxSoFar = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }

    int kadaneMinSum(vector<int>& arr) {
        int minEndingHere = arr[0], minSoFar = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            minEndingHere = min(arr[i], minEndingHere + arr[i]);
            minSoFar = min(minSoFar, minEndingHere);
        }
        return minSoFar;
    }
    int maxCircularSum(vector<int> &arr) {
        // code here
         int totalSum = 0;
        for (int num : arr) totalSum += num;

        int maxKadane = kadaneMaxSum(arr);       // Case 1: Non-wrapping
        int minKadane = kadaneMinSum(arr);       // Used for Case 2

        if (maxKadane < 0) 
            return maxKadane; // All elements are negative

        int circularSum = totalSum - minKadane;  // Case 2: Wrapping

        return max(maxKadane, circularSum);
    }
};