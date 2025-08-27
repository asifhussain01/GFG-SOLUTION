class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort the array
        int count = 0;

        // Fix the largest side one by one
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    // If arr[i] + arr[j] > arr[k],
                    // then all pairs from i..j-1 with arr[j] will also work
                    count += (j - i);
                    j--; 
                } else {
                    i++; 
                }
            }
        }
        return count;
    }
};
