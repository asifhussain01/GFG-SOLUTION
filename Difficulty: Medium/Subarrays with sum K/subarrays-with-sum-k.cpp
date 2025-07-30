class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int, int> prefixSumCount;
        int count = 0, sum = 0;

        // Initialize with prefix sum 0 seen once
        prefixSumCount[0] = 1;

        for (int num : arr) {
            sum += num;

            // Check if there is a prefix sum that when removed gives sum k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Store current prefix sum
            prefixSumCount[sum]++;
        }

        return count;
    
    }
};