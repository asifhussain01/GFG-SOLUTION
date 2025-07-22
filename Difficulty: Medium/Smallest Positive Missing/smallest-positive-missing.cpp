class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
         int n = arr.size();
        
        // Place each number at its correct index
        for(int i = 0; i < n; ++i) {
            while(arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Find the first index where the number is not i + 1
        for(int i = 0; i < n; ++i) {
            if(arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers 1 to n are present
        return n + 1;
    }
};