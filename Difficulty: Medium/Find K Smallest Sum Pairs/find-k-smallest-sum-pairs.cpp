class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> result;
        int n = arr1.size(), m = arr2.size();
        if (n == 0 || m == 0 || k == 0) return result;
        
        // Min-heap: stores {sum, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Push first k elements from arr1 with arr2[0]
        for (int i = 0; i < n && i < k; i++) {
            minHeap.push({arr1[i] + arr2[0], i, 0});
        }
        
        // Extract k pairs with smallest sums
        while (k-- > 0 && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            int i = top[1];
            int j = top[2];
            
            result.push_back({arr1[i], arr2[j]});
            
            // Push next element from arr2 for the same arr1[i]
            if (j + 1 < m) {
                minHeap.push({arr1[i] + arr2[j + 1], i, j + 1});
            }
        }
        
        return result;
    }
};
