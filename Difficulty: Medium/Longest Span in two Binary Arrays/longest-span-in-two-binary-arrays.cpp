class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
    unordered_map<int, int> diffMap; // maps diff to first index
    int maxLen = 0;
    int preSum1 = 0, preSum2 = 0;

    for (int i = 0; i < n; i++) {
        preSum1 += a1[i];
        preSum2 += a2[i];

        int diff = preSum1 - preSum2;

        if (diff == 0) {
            maxLen = i + 1;
        } else if (diffMap.find(diff) != diffMap.end()) {
            maxLen = max(maxLen, i - diffMap[diff]);
        } else {
            diffMap[diff] = i;
        }
    }

    return maxLen;
    }
};