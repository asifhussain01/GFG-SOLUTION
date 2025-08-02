class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
    vector<int> temp(n);
    
    // Step 1: Convert to +1 / -1
    for (int i = 0; i < n; ++i) {
        temp[i] = (arr[i] > k) ? 1 : -1;
    }

    // Step 2: Use prefix sum and hashmap to track first occurrence
    unordered_map<int, int> firstIndex;
    int maxLen = 0, prefixSum = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += temp[i];

        if (prefixSum > 0) {
            maxLen = i + 1;  // Whole subarray from 0 to i is valid
        } else {
            if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefixSum - 1]);
            }
        }

        // Store first occurrence of prefixSum
        if (firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }
    }

    return maxLen;
    }
};